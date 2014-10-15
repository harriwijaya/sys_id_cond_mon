% RLS test
% -------------------------------------------------------------------------

% W(n+1) = W(n) + beta*error(n)*X(n)

% let's find coefficients of y(n) = a + b*n = (a b) * (1 n)'
% the unknown system is [y(n)=2+3*n]

clear % clear previous variables

lambda = 0.6;
% good for change: 0.7; not good with change: 0.999;
delta = 1/100;
M = 3;

% simulate samples
num_sam = 50; % let's limit for simulation purpose
num_group = 8;%8;
change = 4;

% init
w = zeros(M,1);
P = eye(M) / delta;

u = zeros(M,1);
u = u(:); % ensure column vector

% plotting purpose
d_plot = transpose(zeros(1,num_sam));
y_plot = transpose(zeros(1,num_sam));
e_plot = transpose(zeros(1,num_sam));

%
w1 = transpose(zeros(1,num_sam));
w2 = transpose(zeros(1,num_sam));
w3 = transpose(zeros(1,num_sam));

noise = 0.01;

for m = 1:num_group
for n = 1:num_sam
    % simulate real output of the unknown system
    % single output: d(1)
    if (m <= change)
        d = (0.5+0.1*n-0.001*n*n) + ((noise+noise)*rand-noise); %noise between -1 to +1
        %d = (0.5+0.1*n-0.1*n*n) + ((noise+noise)*rand-noise);
    else
        d = (0.5+0.15*n-0.0015*n*n) + ((noise+noise)*rand-noise);
        %d = (0.5+0.15*n-0.15*n*n) + ((noise+noise)*rand-noise);
    end
    
    % 3 inputs: u(3) u(2) u(1)
    u(1) = n*n;
    u(2) = n; % generally: f(n)
    u(3) = 1; % artificial input
    
    %
    k = ( (P*u) / (1 + (u' * P * u) / lambda) ) / lambda;
    y = w' * u;
    e = d - y;
    w = w + k*e;
    P = ( P - k * u' * P ) / lambda;
    
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

% display(w) --transition is not stable!

plot(d_plot)
hold on
plot(y_plot, '*g')
plot(e_plot, '.r')
legend('d - system output','y - RLS output','e - error')
%plot(w1, '+m');plot(w2, '+g');plot(w3, '+r')
hold off

