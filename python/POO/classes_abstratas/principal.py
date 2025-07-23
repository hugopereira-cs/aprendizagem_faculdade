from Classes.ContaComum import ContaComum
from Classes.ContaVIP import ContaVIP

cc1 = ContaComum(1, 0.1, 0.25, 2000, 0.05)
cvip1 = ContaVIP(2, 0.1, 0.25, 2000, 0.05)

cc1.calculo_rendimento()
cvip1.calculo_rendimento()

cc1.extrato()
cvip1.extrato()