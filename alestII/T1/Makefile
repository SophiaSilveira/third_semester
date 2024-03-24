SILENT := @

all: run app50 run50

run: 
	@echo " Mapa Escolhido | Montante Recolhido | Tempo de Execucao | Numero de Operacoes"
	

app50: app.cpp
	$(SILENT) g++ -o app50 app.cpp

run50: app50
	$(SILENT) echo "casoA50" | cat - maps/casoA50.txt |  ./app50