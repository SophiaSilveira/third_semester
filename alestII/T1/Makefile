SILENT := @

all: 		run run50 run100 run200 run500 run750 run1000 run1500 run2000 clean

run: 
			@echo " Mapa Escolhido | Montante Recolhido | Tempo de Execucao | Numero de Operacoes"
	

app50: 		app.cpp
			$(SILENT) g++ -o app50 app.cpp

run50: 		app50
			$(SILENT) echo "casoA50" | cat - maps/casoA50.txt |  ./app50


app100: 	app.cpp
			$(SILENT) g++ -o app100 app.cpp

run100: 	app100
			$(SILENT) echo "casoA100" | cat - maps/casoA100.txt |  ./app100


app200: 	app.cpp
			$(SILENT) g++ -o app200 app.cpp

run200: 	app200
			$(SILENT) echo "casoA200" | cat - maps/casoA200.txt |  ./app200


app500: 	app.cpp
			$(SILENT) g++ -o app500 app.cpp

run500: 	app500
			$(SILENT) echo "casoA500" | cat - maps/casoA500.txt |  ./app500


app750: 	app.cpp
			$(SILENT) g++ -o app750 app.cpp

run750: 	app750
			$(SILENT) echo "casoA750" | cat - maps/casoA750.txt |  ./app750


app1000: 	app.cpp
			$(SILENT) g++ -o app1000 app.cpp

run1000: 	app1000
			$(SILENT) echo "casoA1000" | cat - maps/casoA1000.txt |  ./app1000


app1500: 	app.cpp
			$(SILENT) g++ -o app1500 app.cpp

run1500: 	app1500
			$(SILENT) echo "casoA1500" | cat - maps/casoA1500.txt |  ./app1500


app2000: 	app.cpp
			$(SILENT) g++ -o app2000 app.cpp

run2000: 	app2000
			$(SILENT) echo "casoA2000" | cat - maps/casoA2000.txt |  ./app2000

clean: 
			@rm -f app50 app100 app200 app500 app750 app1000 app1500 app2000