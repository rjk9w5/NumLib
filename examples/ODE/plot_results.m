clear all
close all
clc
results

x = 0:0.1:2;
figure(1)
hold on
plot(x,p1_analytic, '-k', 'LineWidth', 2)
plot(x, heun_sol, '.-k', 'LineWidth', 2)
title('Heun and Analytical')
xlabel('x')
ylabel('y')
legend('Actual', 'Heun','Location', 'northwest')

figure(2)
hold on
plot(x,p1_analytic, '-k', 'LineWidth', 2)
plot(x, mideuler_sol, '.-k', 'LineWidth', 2)
title('Mid-Point Euler and Analytical')
xlabel('x')
ylabel('y')
legend('Actual','Mid-Point Euler','Location', 'northwest')

figure(3)
hold on
plot(x,p1_analytic, '-k', 'LineWidth', 2)
plot(x, modeuler_sol, '.-k', 'LineWidth', 2)
title('Modified Euler and Analytical')
xlabel('x')
ylabel('y')
legend('Actual', 'Modified Euler','Location', 'northwest')

figure(3)
hold on
plot(x,p1_analytic, '-k', 'LineWidth', 2)
plot(x, mideuler_sol, '.-k', 'LineWidth', 2)
title('Modified Euler and Analytical')
xlabel('x')
ylabel('y')
legend('Actual', 'Modified Euler','Location', 'northwest')

figure(8)
hold on
plot(x,p1_analytic, '-k', 'LineWidth', 2)
plot(x, rk4_sol, '.-k', 'LineWidth', 2)
title('Runge-Kutta 4-step and Analytical')
xlabel('x')
ylabel('y')
legend('Actual', 'RK4','Location', 'northwest')

figure(4)
subplot(1,2,1)
hold on
plot(x,mideuler_err, '--k', 'LineWidth', 2)
plot(x,modeuler_err, ':k', 'LineWidth', 2)
plot(x,heun_err, '.-k', 'LineWidth', 2)
title('Error Distribution')
xlabel('x')
ylabel('error')
legend('Mid-Point Euler', 'Modified Euler', 'Heun','Location', 'northwest')

subplot(1,2,2)
plot(x,rk4_err,'*-k', 'LineWidth', 2)
title('Error Distribution (RK4)')
xlabel('x')
ylabel('error')

figure(5)
hold on
plot(x+1,p2_analytic, '-k', 'LineWidth', 2)
plot(x+1, ab2_sol, '.-k', 'LineWidth', 2)
title('Adams-Bashfort 2-Step and Analytical')
xlabel('x')
ylabel('y')
legend('Actual', '2-Step')

figure(6)
hold on
plot(x+1,p2_analytic, '-k', 'LineWidth', 2)
plot(x+1, ab3_sol, '.-k', 'LineWidth', 2)
title('Adams-Bashfort 3-Step and Analytical')
xlabel('x')
ylabel('y')
legend('Actual', '3-Step')

figure(7)
hold on
plot(x+1,ab2_err, '--k', 'LineWidth', 2)
plot(x+1,ab3_err, ':k', 'LineWidth', 2)
plot(x+1,ab4_err, ':k', 'LineWidth', 2)
plot(x+1,ab5_err, ':k', 'LineWidth', 2)
title('Error Distribution for Adams-Bashfort Methods')
xlabel('x')
ylabel('error')
legend('2-Step', '3-Step', '4-Step', '5-Step')

