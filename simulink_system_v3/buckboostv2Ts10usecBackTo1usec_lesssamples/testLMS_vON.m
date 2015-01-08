% LMS test
% -------------------------------------------------------------------------

% W(n+1) = W(n) + beta*error(n)*X(n)

% let's find coefficients of y(n) = a + b*n = (a b) * (1 n)'
% the unknown system is [y(n)=2+3*n]

close all % close all figures
clear % clear previous variables

beta = 0.75;%0.5;%0.75;%0.4;%0.0001;% 0.01;

M = 2; 

% simulate samples
num_sam = 100;%500;%100;%50; % let's limit for simulation purpose
num_group = 1;%8;
change = 4;

% init
w = zeros(M,1);

u = zeros(M,1);
u = u(:); % ensure column vector

% plotting purpose
d_plot = transpose(zeros(1,num_sam));
y_plot = transpose(zeros(1,num_sam));
e_plot = transpose(zeros(1,num_sam));
d2_plot= transpose(zeros(1,num_sam));

%
w1 = transpose(zeros(1,num_sam));
w2 = transpose(zeros(1,num_sam));

noise = 0.01;

v0 = 40;%50; %=VOLT
ESR = 75e-3;%75e-3; %=OHM
C = 1.25e-3;%1.25e-3; %=FARAD
R = 30;%30; %=OHM

step_size = 1e-5;


for m = 1:num_group
for n = 1:num_sam
    % simulate real output of the unknown system
    %if (m <= change)
    %    d = (0.5+0.1*n-0.001*n*n) + ((noise+noise)*rand-noise); %noise between -1 to +1
    %    %d = (0.5+0.1*n-0.1*n*n) + ((noise+noise)*rand-noise);
    %else
    %    d = (0.5+0.15*n-0.0015*n*n) + ((noise+noise)*rand-noise);
    %    %d = (0.5+0.15*n-0.15*n*n) + ((noise+noise)*rand-noise);
    %end
    t = n - 1;
    t = t * step_size;
    d = v0*exp(-1/(R*C) * t);
    d2= v0 - v0/(R*C) * t;
    
       
    % 3 inputs: u(3) u(2) u(1)
    u(2) = t; % generally: f(n)
    u(1) = 1; % artificial input
    rms = (u(1)^2 + u(2)^2)/2;
    
    %
    y = w' * u;
    e = d - y;
    w = w + beta*e*u/rms;
    
    %
    if( (n == num_sam/2) && (m == change))
        display('Before Change:')
        display(w)
    end
    
    if( (n == num_sam/2) && (m == num_group))
        display('After Change:')
        display(w)
        display('estimated C=')
        display(-w(1)/w(2)/30 )
        %display(-w(1)/w(2)/30 * step_size)
    end
    
    % plotting purpose
    d_plot((m-1)*num_sam + n) = d;
    y_plot((m-1)*num_sam + n) = y;
    e_plot((m-1)*num_sam + n) = e;
    d2_plot((m-1)*num_sam + n) = d2;
    
    %
    w1((m-1)*num_sam + n) = w(1);
    w2((m-1)*num_sam + n) = w(2);
    
    
    
    
end
end

% display(w)

figure(1)
plot(d_plot)
hold on
plot(y_plot, '*g')
%ylim([40,40.5])
plot(d2_plot, '+r')
%plot(e_plot, '.r')
tt = [0:step_size:num_sam*step_size]; plot(w(1)+w(2)*tt, '-r')
%legend('d - system output','y - LMS output','e - error')
%legend('d - system output','y - LMS output','d2 - approx sys out')
%plot(w1, '+y');plot(w2, '+y');plot(w3, '+y')
hold off
figure(2)
plot(w1)
legend('w1')
figure(3)
plot(w2)
legend('w2')
