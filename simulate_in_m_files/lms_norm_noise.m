% LMS test
% -------------------------------------------------------------------------

% W(n+1) = W(n) + beta*error(n)*X(n)

% let's find coefficients of y(n) = a + b*n = (a b) * (1 n)'
% the unknown system is [y(n)=2+3*n]

clear % clear previous variables

beta = 0.4;%0.0001;% 0.01;
% this 0.0000001 oscilating once the system is changed
N = 3; % order is 2, since 2 coefficients

% simulate samples
num_sam = 50; % let's limit for simulation purpose
num_group = 8;
change = 4;

% init
w = transpose(zeros(1,N));
x = transpose(zeros(1,N));

% plotting purpose
d_plot = transpose(zeros(1,num_sam));
y_plot = transpose(zeros(1,num_sam));
e_plot = transpose(zeros(1,num_sam));

%
w1 = transpose(zeros(1,num_sam));
w2 = transpose(zeros(1,num_sam));
w3 = transpose(zeros(1,num_sam));

noise = 0.02;

for m = 1:num_group
for n = 1:num_sam
    % simulate real output of the unknown system
    if (m <= change)
        d = (0.5+0.1*n-0.001*n*n) + ((noise+noise)*rand-noise); %noise between -1 to +1
        %d = (0.5+0.1*n-0.1*n*n) + ((noise+noise)*rand-noise);
    else
        d = (0.5+0.15*n-0.0015*n*n) + ((noise+noise)*rand-noise);
        %d = (0.5+0.15*n-0.15*n*n) + ((noise+noise)*rand-noise);
    end
    
    x(1) = n*n;
    x(2) = n; % generally: f(n)
    x(3) = 1; % artificial input
    
    rms = (x(1)^2+x(2)^2+x(3)^2)/3; %rms^2
    
    y = w'*x; %whole matrix
    
    e = d - y;
    
    % adapat weight
    w = w + beta*e*x/rms;
    
    % sliding windows
    %for idx = 1 : (N-1)
    %    x(idx+1) = x(idx);
    %end
    
    %
    if( (n == num_sam/2) && (m == change))
        display('Before Change:')
        display(w)
    end
    
    if( (n == num_sam/2) && (m == num_group))
        display('After Change:')
        display(w)
    end
    
    % plotting purpose
    d_plot((m-1)*num_sam + n) = d;
    y_plot((m-1)*num_sam + n) = y;
    e_plot((m-1)*num_sam + n) = e;
    
    %
    w1((m-1)*num_sam + n) = w(1);
    w2((m-1)*num_sam + n) = w(2);
    w3((m-1)*num_sam + n) = w(3);
    
    
end
end

% display(w)

plot(d_plot)
hold on
plot(y_plot, '*g')
plot(e_plot, '.r')
legend('d - system output','y - LMS output','e - error')
%plot(w1, '+y');plot(w2, '+y');plot(w3, '+y')
hold off

