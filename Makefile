all: compile run clean push

compile: Database.cpp
	g++ -Wall Database.cpp -o Database.out

run: Database.out
	./Database.out

clean:
	rm -rf *.out


push: .git
	git add .
	git commit -m "auto"
	git push origin master
