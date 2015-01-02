function [y, e, w0, w1, Capout, ...
    yi, ei, wi0, wi1, ...
    yu, eu, wu0, wu1, wu2, ESRout, ...
    ESRavrg, ...
    Vnoise, Inoise, ...
    t0]  = ...
    Est_LMS(start,t,duty,v_out,i_in, ...
    w0in, w1in, Capin, ...
    wi0in, wi1in, ...
    wu0in, wu1in, wu2in, ESRin, ...
    ESRin0, ESRin1, ESRin2, ESRin3, ESRin4, ESRin5, ESRin6, ESRin7, ...
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
beta = 0.5;

% <<~~~ uON(t) = w0 + w1*t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>>

% ... estimator output ...
y = 0.0;
e = 0.0;

% ... inputs ...
u = transpose(zeros(1,2));
u(1) = 1;
u(2) = t;

% ... coefficients ...
w = transpose(zeros(1,2));
w(1) = w0in;
w(2) = w1in;
w0 = w0in; w1 = w1in;

% ... algorithm specific tools ...
% none

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
% none

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
% none

% --- end of Init ---------------------------------------------------------

% *** Misc. ***************************************************************

Capout = Capin;
ESRout = ESRin;
t0 = t0in;

Vnoise = 0.0;
Inoise = 0.0;

ESRavrg = (ESRin0+ESRin1+ESRin2+ESRin3+ESRin4+ESRin5+ESRin6+ESRin7)/8;

% --- end of Misc. --------------------------------------------------------

noiseAmp = 0;%0.02; % rand : [0,1]; 
% variance of amplitude is 0.1 V in ON, 0.5 V in OFF.
% variance of amplitude is 4 A in ON/OFF.
% to take noise 10% of minium: (0.1V)*0.1 = 0.01

if(start==1)
    % *** State: ON *******************************************************
    if(t > OFFSET_ON_START_abs && offset < OFFSET_ON_END_rel) % ON
        % estimate the "C"
        %if(t > OFFSET_ON_START_abs && t<= OFFSET_ON_START_abs+2)
        if(t <= OFFSET_ON_START_abs+2)
            t0 = t;
        %else
        end
            % --- start of LMS for uON(t) ---
            u(2) = (t - t0) ;%* sampling_time; 
            rms = (u(1)^2 + u(2)^2)/2;
            y = w' * u;
            %e = v_out - y;
            Vnoise = v_out + (noiseAmp*rand);
            e = (v_out + (noiseAmp*rand)) - y;

            w = w + beta*e*u/rms;
            w0 = w(1); w1 = w(2);

            % --- end of LMS for uON(t) ---
        %end
    end
    if(offset >= OFFSET_ON_END_rel && offset <= OFFSET_ON_END_rel+1)
        Capout = -w0/w1/30 * sampling_time;% *sampling_time;%R=30
    end
    % --- end State: ON ---------------------------------------------------
    
    % *** State: OFF ******************************************************
    if(offset > OFFSET_OFF_START_rel && t < OFFSET_OFF_END_abs) % OFF
        % estimate the "ESR"
        if(offset > OFFSET_OFF_START_rel && offset <= OFFSET_OFF_START_rel+2)
            t0 = t;
        %else
        end
            % --- start LMS for iLOFF(t) ---
            %u(2) = (t - t0) * sampling_time; 
            u(2) = (t - t0); 
            rms = (u(1)^2 + u(2)^2)/2;
            yi = wi' * u;
            %ei = i_in - yi;
            Inoise = i_in + (noiseAmp*rand);
            ei = (i_in + (noiseAmp*rand)) - yi;

            wi = wi + beta*ei*u/rms;
            wi0 = wi(1); wi1 = wi(2);

            % --- end of LMS for iLOFF(t) ---

            % --- start LMS for uOFF(t) ---
            %uu(2) = (t - t0) * sampling_time; 
            uu(2) = (t - t0); 
            uu(3) = uu(2)*uu(2);
            rmsu = (uu(1)^2 + uu(2)^2 + uu(3)^2)/2;%3;
            yu = wu' * uu;
            %eu = v_out - yu;
            Vnoise = v_out + (noiseAmp*rand);
            eu = (v_out + (noiseAmp*rand)) - yu;

            wu = wu + beta*eu*uu/rmsu;
            wu0 = wu(1); wu1 = wu(2); wu2 = wu(3);

            % --- end of LMS for uOFF(t) ---
        %end
    end
    if(t >= OFFSET_OFF_END_abs && t <= OFFSET_OFF_END_abs+1)
        wu2real = wu2 / sampling_time^2;
        wu1real = wu1 / sampling_time;
        wu0real = wu0;
        wi1real = wi1 / sampling_time;
        wi0real = wi0;
        a = 2*wu2real / (wi1real*30 - wu1real);
        b = 2*wu2real / (1 - wu1real/30/wi1real);
        c = wu0real*a + b/a - 2*wu2real/a;
        ESRout = (wi0real/Capin - c) / (c/30 - wi1real);
    end
    % --- end State: OFF --------------------------------------------------

end
