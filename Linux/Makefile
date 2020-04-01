# Must be run on machine
all: 

create: pregame database tables tuples grant query functions


clean: unguent drop destroy endgame


pregame:
	cd /home; sudo mkdir senior_project
	cd /home; sudo mkdir senior_project/TheTablespace
	cd /home; sudo mkdir senior_project/TheTablespaceIndex
	sudo chmod 700 /home/senior_project
	sudo chown postgres:postgres /home/senior_project
	sudo chmod 700 /home/senior_project/TheTablespace
	sudo chown postgres:postgres /home/senior_project/TheTablespace
	sudo chmod 700 /home/senior_project/TheTablespaceIndex
	sudo chown postgres:postgres /home/senior_project/TheTablespaceIndex
	sudo mv /home/senior_project/TheTablespaceIndex /home/senior_project/TheTablespace

database:
	psql -d postgres -f Create_User_Tablespaces.psql
	
tables:
	psql -d thedatabase -f Create_Tables.psql

tuples:
	psql -d thedatabase -f Insert_All.psql

grant:
	psql -d thedatabase -f Grant_All.psql

query:
	psql -d thedatabase -f Query_All.psql

functions:
	psql -d thedatabase -f Create_Functions.psql

ungrant:
	psql -d thedatabase -f Ungrant_All.psql

drop:
	psql -d thedatabase -f Drop_Tables.psql

destroy:
	psql -d postgres -f Drop_User_Tablespaces.psql

endgame:
	cd /home; sudo rm -fr senior_project

push: .git
	git add .
	git commit -m "auto"
	git push origin master

