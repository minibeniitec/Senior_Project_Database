all: compile run clean

compile: Database.cpp
	g++ -Wall Database.cpp -o Db.out

run: Db.out
	./Db.out

clean:
	rm -rf *.out

push: .git
	git add .
	git commit -m "auto"
	git push origin master
