results
n = 2:2:40;
figure(1)
hold on
loglog(1./n,abs(trap-actual)/abs(actual),'b','LineWidth', 2)
title('Error Plot')
xlabel('log n panels')
ylabel('log n error')

loglog(1./n,abs(simp3-actual)/abs(actual),'r','LineWidth', 2)
xlabel('log n panels')
ylabel('log n error')

legend('Trapezoidal Method', 'Simpsons 1/3 Method')