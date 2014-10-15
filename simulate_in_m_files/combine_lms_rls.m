% LMS test
% -------------------------------------------------------------------------

% W(n+1) = W(n) + beta*error(n)*X(n)

% let's find coefficients of y(n) = a + b*n = (a b) * (1 n)'
% the unknown system is [y(n)=2+3*n]

clear % clear previous variables

beta = 0.0000001;%0.0001;% 0.01;
N = 3; % order is 2, since 2 coefficients

% simulate samples
num_sam = 50; % let's limit for simulation purpose
num_group = 5;%8;

% init
w = transpose(zeros(1,N));
x = transpose(zeros(1,N));

% plotting purpose
d_plot = transpose(zeros(1,num_sam));
y_plot = transpose(zeros(1,num_sam));
e_plot = transpose(zeros(1,num_sam));

for m = 1:num_group
for n = 1:num_sam
    % simulate real output of the unknown system
    d = (2+0.01*n-0.2*n*n) + (2*rand-1); %noise between -1 to +1
    
    x(3) = n*n;
    x(2) = n; % generally: f(n)
    x(1) = 1; % artificial input
    
    y = 0;
    y = y + w'*x; %whole matrix
    
    e = d - y;
    
    % adapat weight
    w = w + beta*e*x;
    
    % sliding windows
    %for idx = 1 : (N-1)
    %    x(idx+1) = x(idx);
    %end
    
    % plotting purpose
    d_plot((m-1)*num_sam + n) = d;
    y_plot((m-1)*num_sam + n) = y;
    e_plot((m-1)*num_sam + n) = e;
    
    
    
end
end

display(w)

subplot(2,1,1); plot(d_plot)
hold on
subplot(2,1,1); plot(y_plot, '*g')
subplot(2,1,1); plot(e_plot, '.r')
title('LMS')
legend('d - system output','y - LMS output','e - error','location', 'eastoutside')
hold off

% RLS test
% -------------------------------------------------------------------------

% W(n+1) = W(n) + beta*error(n)*X(n)

% let's find coefficients of y(n) = a + b*n = (a b) * (1 n)'
% the unknown system is [y(n)=2+3*n]

clear % clear previous variables

lambda = 0.999;
N = 3+1; % 3 input + 1 output
inporder = 3; % in this case

% simulate samples
num_sam = 50; % let's limit for simulation purpose
num_group = 5;%8;

% init
P = 100 * eye(N);
w = zeros(N,1);
u = zeros(N,1);
x = zeros(inporder,1);
%w = transpose(zeros(1,N));
%x = transpose(zeros(1,N));

% plotting purpose
d_plot = transpose(zeros(1,num_sam));
y_plot = transpose(zeros(1,num_sam));
e_plot = transpose(zeros(1,num_sam));

for m = 1:num_group
for n = 1:num_sam
    % simulate real output of the unknown system
    % single output: d(1)
    d = (2+0.01*n-0.2*n*n) + (2*rand-1); %noise between -1 to +1
    
    % 3 inputs: u(3) u(2) u(1)
    x(1) = n*n;
    x(2) = n; % generally: f(n)
    x(3) = 1; % artificial input
    
    u = [ x; d];
    
    phi = u' * P;
    k = phi'/(lambda + phi * u);
    
    y = w' * u;
    
    e = d - y;
    w = w + k*e;
    P = (P - k*phi) / lambda;
    
    % plotting purpose
    d_plot((m-1)*num_sam + n) = d;
    y_plot((m-1)*num_sam + n) = y;
    e_plot((m-1)*num_sam + n) = e;
    
    
    
end
end

display(w)

subplot(2,1,2); plot(d_plot)
hold on
subplot(2,1,2); plot(y_plot, '*g')
subplot(2,1,2); plot(e_plot, '.r')
title('RLS')
legend('d - system output','y - RLS output','e - error', 'location', 'eastoutside')
hold off

