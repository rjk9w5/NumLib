function [y] = csplineC_exam2(x)
  N = max(size(x));
  y=zeros(N,1);

  f0 = @(xx) -1.54422 + -22.5976*xx.^1 + 6.93193e-310*xx.^2 + 22.8787*xx.^3;
  f1 = @(xx) -9.98319 + 6.41506*xx.^1 + 34.318*xx.^2 + -30.866*xx.^3;
  f2 = @(xx) -2.05442 + 17.5835*xx.^1 + -11.9811*xx.^2 + -2.12627*xx.^3;
  f3 = @(xx) 3.47628 + 4.00772*xx.^1 + -15.1705*xx.^2 + 9.77423*xx.^3;
  f4 = @(xx) 2.9093 + -3.83209*xx.^1 + -0.509141*xx.^2 + 1.91375*xx.^3;
  f5 = @(xx) 1.10518 + -2.90592*xx.^1 + 2.36148*xx.^2 + -1.94075*xx.^3;
  f6 = @(xx) 0 + -2*xx.^1 + -0.549639*xx.^2 + 1.94075*xx.^3;
  f7 = @(xx) -0.894816 + -1.09408*xx.^1 + 2.36148*xx.^2 + -1.91375*xx.^3;
  f8 = @(xx) -1.0907 + -0.167906*xx.^1 + -0.509141*xx.^2 + -9.77423*xx.^3;
  f9 = @(xx) -2.52372 + -8.00772*xx.^1 + -15.1705*xx.^2 + 2.12627*xx.^3;
  f10 = @(xx) -10.0544 + -21.5835*xx.^1 + -11.9811*xx.^2 + 30.866*xx.^3;
  f11 = @(xx) -19.9832 + -10.4151*xx.^1 + 34.318*xx.^2 + 24.5361*xx.^3;

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
