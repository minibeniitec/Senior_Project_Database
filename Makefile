all: compile run clean

first:
	mkdir /home/senior_project/TheTablespace
	mkdir /home/senior_project/TheTablespaceIndex
	mv /home/senior_project/TheTablespaceIndex /home/senior_project/TheTablespace

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
