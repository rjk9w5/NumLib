function [y] = csplineN_exam2(x)
  N = max(size(x));
  y=zeros(N,1);

  f0 = @(xx) -1.54422 + -25.7738*xx.^1 + 0*xx.^2 + 35.5834*xx.^3;
  f1 = @(xx) -9.98319 + 0.913762*xx.^1 + 53.3751*xx.^2 + -46.9751*xx.^3;
  f2 = @(xx) -2.05442 + 19.0575*xx.^1 + -17.0876*xx.^2 + 2.19054*xx.^3;
  f3 = @(xx) 3.47628 + 3.61289*xx.^1 + -13.8017*xx.^2 + 8.61606*xx.^3;
  f4 = @(xx) 2.9093 + -3.72681*xx.^1 + -0.87765*xx.^2 + 2.22961*xx.^3;
  f5 = @(xx) 1.10518 + -2.93224*xx.^1 + 2.46677*xx.^2 + -2.04604*xx.^3;
  f6 = @(xx) 0 + -2*xx.^1 + -0.602283*xx.^2 + 2.04604*xx.^3;
  f7 = @(xx) -0.894816 + -1.06776*xx.^1 + 2.46677*xx.^2 + -2.22961*xx.^3;
  f8 = @(xx) -1.0907 + -0.273194*xx.^1 + -0.87765*xx.^2 + -8.61606*xx.^3;
  f9 = @(xx) -2.52372 + -7.61289*xx.^1 + -13.8017*xx.^2 + -2.19054*xx.^3;
  f10 = @(xx) -10.0544 + -23.0575*xx.^1 + -17.0876*xx.^2 + 46.9751*xx.^3;
  f11 = @(xx) -19.9832 + -4.91376*xx.^1 + 53.3751*xx.^2 + -35.5834*xx.^3;

  for i = 1:1:N
    if -3 <= x(i) && -2.5 > x(i)
      y(i) = f0(x(i) - -3);
    elseif -2.5 <= x(i) && -2 > x(i)
      y(i) = f1(x(i) - -2.5);
    elseif -2 <= x(i) && -1.5 > x(i)
      y(i) = f2(x(i) - -2);
    elseif -1.5 <= x(i) && -1 > x(i)
      y(i) = f3(x(i) - -1.5);
    elseif -1 <= x(i) && -0.5 > x(i)
      y(i) = f4(x(i) - -1);
    elseif -0.5 <= x(i) && 0 > x(i)
      y(i) = f5(x(i) - -0.5);
    elseif 0 <= x(i) && 0.5 > x(i)
      y(i) = f6(x(i) - 0);
    elseif 0.5 <= x(i) && 1 > x(i)
      y(i) = f7(x(i) - 0.5);
    elseif 1 <= x(i) && 1.5 > x(i)
      y(i) = f8(x(i) - 1);
    elseif 1.5 <= x(i) && 2 > x(i)
      y(i) = f9(x(i) - 1.5);
    elseif 2 <= x(i) && 2.5 > x(i)
      y(i) = f10(x(i) - 2);
    elseif 2.5 <= x(i) && 3 >= x(i)
      y(i) = f11(x(i) - 2.5);
    elseif 3 < x(i)
      fprintf('Warning: Evaluating Cublic Spline above range\n')
      y(i) = f11(x(i) - 2.5);
    elseif -3 > x(i)
      fprintf('Warning: Evaluating Cublic Spline below range\n')
      y(i) = f0(x(i) - -3);
  end
end
