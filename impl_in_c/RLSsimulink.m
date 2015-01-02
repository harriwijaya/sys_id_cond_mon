function [y, e, w0, w1, P11, P12, P21, P22, Capout, ...
    yi, ei, wi0, wi1, Pi11, Pi12, Pi21, Pi22, ...
    yu, eu, wu0, wu1, wu2, Pu11, Pu12, Pu13, Pu21, Pu22, Pu23, Pu31, Pu32, Pu33, ESRout, ...
    Vnoise, Inoise, ...
    t0]  = ...
    Est_RLS(start,t,duty,v_out,i_in, ...
    w0in, w1in, P11in, P12in, P21in, P22in, Capin, ...
    wi0in, wi1in, Pi11in, Pi12in, Pi21in, Pi22in, ...
    wu0in, wu1in, wu2in, Pu11in, Pu12in, Pu13in, Pu21in, Pu22in, Pu23in, Pu31in, Pu32in, Pu33in, ESRin, ...
    t0in)
%#codegen

% *** Time Partition ******************************************************
sampling_time = 1e-5;% 1e-6;

offset = t - duty;

OFFSET_ON_START_abs = 0+5; % for t
OFFSET_ON_END_rel = -5; % for offset
OFFSET_OFF_START_rel = 5; % for offset
OFFSET_OFF_END_abs = 90+5; % for t
% --- end of Time Partition -----------------------------------------------

% *** Init ****************************************************************
lambda = 0.6;
% good for change: 0.7; not good with change: 0.999;
delta = 1/100;

% <<~~~ uON(t) = w0 + w1*t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>>

% ... estimator output ...
y = 0.0;
e = 0.0;

% ... inputs ...
u = transpose(zeros(1,2));
u(1) = 1;
u(2) = t;

% ... coefficients ...
w = zeros(2,1);
w(1) = w0in;
w(2) = w1in;
w0 = w0in; w1 = w1in;

% ... algorithm specific tools ...
P = eye(2) / delta;
P(1,1) = P11in; P(1,2) = P12in;
P(2,1) = P21in; P(2,2) = P22in;
%NOTE: in "delay unit" blocks, set:
% P11in and P22in --> 100 (as per 'delta')
% P12in and P21in --> 0 (since "eye" matrix)
P11 = P11in; P12 = P12in;
P21 = P21in; P22 = P22in;

% <<~~~ iLOFF(t) = wi0 + wi1*t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>>

% ... estimator output ...
yi = 0.0;
ei = 0.0;

% ... inputs ...
% REUSE

% ... coefficients ...
wi = zeros(2,1);
wi(1) = wi0in;
wi(2) = wi1in;
wi0 = wi0in; wi1 = wi1in;

% ... algorithm specific tools ...
Pi = eye(2) / delta;
Pi(1,1) = Pi11in; Pi(1,2) = Pi12in;
Pi(2,1) = Pi21in; Pi(2,2) = Pi22in;
%NOTE: in "delay unit" blocks, set:
% P11in and P22in --> 100 (as per 'delta')
% P12in and P21in --> 0 (since "eye" matrix)
Pi11 = Pi11in; Pi12 = Pi12in;
Pi21 = Pi21in; Pi22 = Pi22in;

% <<~~~ uON(t) = wu0 + wu1*t + wu2*t^2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>>

% ... estimator output ...
yu = 0.0;
eu = 0.0;

% ... inputs ...
uu = transpose(zeros(1,3));
uu(1) = 1;
uu(2) = t;
uu(3) = t*t;

% ... coefficients ...
wu = zeros(3,1);
wu(1) = wu0in;
wu(2) = wu1in;
wu(3) = wu2in;
wu0 = wu0in; wu1 = wu1in; wu2 = wu2in;

% ... algorithm specific tools ...
Pu = eye(3) / delta;
% TODO: remove P(i,j) with i!=j...
Pu(1,1) = Pu11in; Pu(1,2) = Pu12in; Pu(1,3) = Pu13in;
Pu(2,1) = Pu21in; Pu(2,2) = Pu22in; Pu(2,3) = Pu23in;
Pu(3,1) = Pu31in; Pu(3,2) = Pu32in; Pu(3,3) = Pu33in;
%NOTE: in "delay unit" blocks, set:
% P11in and P22in --> 100 (as per 'delta')
% P12in and P21in --> 0 (since "eye" matrix)
Pu11 = Pu11in; Pu12 = Pu12in; Pu13 = Pu13in;
Pu21 = Pu21in; Pu22 = Pu22in; Pu23 = Pu23in;
Pu31 = Pu31in; Pu32 = Pu32in; Pu33 = Pu33in;

% --- end of Init ---------------------------------------------------------

% *** Misc. ***************************************************************

Capout = Capin;
ESRout = ESRin;
t0 = t0in;

Vnoise = 0.0;
Inoise = 0.0;

% --- end of Misc. --------------------------------------------------------

noiseAmp = 0;%0.02; % rand : [0,1]

if(start==1)
    % *** State: ON *******************************************************
    if(t > OFFSET_ON_START_abs && offset < OFFSET_ON_END_rel) % ON
        % estimate the "C"
        if(t > OFFSET_ON_START_abs && t<= OFFSET_ON_START_abs+2)
            t0 = t;
        else
            % --- start of RLS for uON(t) ---
            %u(2) = t - t0; NOTE: RLS do not require this kind of offsetting!
            u(2) = (t - t0) * sampling_time; %NOTE: not necessary to offset!
            k = ( (P*u) / (1 + (u' * P * u) / lambda) ) / lambda;
            y = w' * u;
            %e = v_out - y;
            Vnoise = v_out + (noiseAmp*rand);
            e = (v_out + (noiseAmp*rand)) - y;

            w = w + k*e;
            w0 = w(1); w1 = w(2);

            P = ( P - k * u' * P ) / lambda;
            P11 = P(1,1); P12 = P(1,2);
            P21 = P(2,1); P22 = P(2,2);
            % --- end of RLS for uON(t) ---
        end
    end
    if(offset >= OFFSET_ON_END_rel && offset <= OFFSET_ON_END_rel+1)
        Capout = -w0/w1/30;%*sampling_time;%R=30
    end
    % --- end State: ON ---------------------------------------------------
    
    % *** State: OFF ******************************************************
    if(offset > OFFSET_OFF_START_rel && t < OFFSET_OFF_END_abs) % OFF
        % estimate the "ESR"
        if(offset > OFFSET_OFF_START_rel && offset <= OFFSET_OFF_START_rel+2)
            t0 = t;
        else
            % --- start RLS for iLOFF(t) ---
            u(2) = (t - t0) * sampling_time; %NOTE: not necessary to offset!
            k = ( (Pi*u) / (1 + (u' * Pi * u) / lambda) ) / lambda;
            yi = wi' * u;
            %ei = i_in - yi;
            Inoise = i_in + (noiseAmp*rand);
            ei = (i_in + (noiseAmp*rand)) - yi;

            wi = wi + k*ei;
            wi0 = wi(1); wi1 = wi(2);

            Pi = ( Pi - k * u' * Pi ) / lambda;
            Pi11 = Pi(1,1); Pi12 = Pi(1,2);
            Pi21 = Pi(2,1); Pi22 = Pi(2,2);
            % --- end of RLS for iLOFF(t) ---

            % --- start RLS for uOFF(t) ---
            uu(2) = (t - t0) * sampling_time; %NOTE: not necessary to offset!
            uu(3) = uu(2)*uu(2);
            ku = ( (Pu*uu) / (1 + (uu' * Pu * uu) / lambda) ) / lambda;
            yu = wu' * uu;
            %eu = v_out - yu;
            Vnoise = v_out + (noiseAmp*rand);
            eu = (v_out + (noiseAmp*rand)) - yu;

            wu = wu + ku*eu;
            wu0 = wu(1); wu1 = wu(2); wu2 = wu(3);

            Pu = ( Pu - ku * uu' * Pu ) / lambda;
            Pu11 = Pu(1,1); Pu12 = Pu(1,2); Pu13 = Pu(1,3);
            Pu21 = Pu(2,1); Pu22 = Pu(2,2); Pu23 = Pu(2,3);
            Pu31 = Pu(3,1); Pu32 = Pu(3,2); Pu33 = Pu(3,3);
            % --- end of RLS for uOFF(t) ---
        end
    end
    if(t >= OFFSET_OFF_END_abs && t <= OFFSET_OFF_END_abs+1)
        a = 2*wu2 / (wi1*30 - wu1);
        b = 2*wu2 / (1 - wu1/30/wi1);
        c = wu0*a + b/a - 2*wu2/a;
        ESRout = (wi0/Capin - c) / (c/30 - wi1);
    end
    % --- end State: OFF --------------------------------------------------

end
