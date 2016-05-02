results

vname = cell(3);
vname{1} = 'Stream Function';
vname{2} = 'u/ue';
vname{3} = 'f"';

for item=1:3
  figure(item)
  hold on
  plot(linspace(0,1,max(size(blas_1))/3), blas_1(item:3:end), 'LineWidth', 2, ':k')
  plot(linspace(0,1,max(size(blas_2))/3), blas_2(item:3:end), 'LineWidth', 2, '.-k')
  plot(linspace(0,1,max(size(blas_5))/3), blas_5(item:3:end), 'LineWidth', 2, '*-k')
  plot(linspace(0,1,max(size(blas_7))/3), blas_7(item:3:end), 'LineWidth', 2, 'o-k')
  plot(linspace(0,1,max(size(blas_10))/3), blas_10(item:3:end), 'LineWidth', 2, '--k')
  plot(linspace(0,1,max(size(blas_converged))/3), blas_converged(item:3:end), 'LineWidth', 2, 'k')
  title(['Solution of ',vname{item}])
  legend('\eta_{max} = 1','\eta_{max} = 2','\eta_{max} = 5','\eta_{max} = 7','\eta_{max} = 10', ['\eta_{max} = ',num2str(converge_at)])
  xlabel('\eta / \eta_{max}')
  ylabel(vname{item})
end

input('Pause...');