# Must be run on machine
all: 

linux: pregame-linux database-linux create

mac: pregame-mac database-mac create

create: tables tuples grant query functions fake

clean: ungrant drop destroy endgame


#Mac Specific
pregame-mac:
	cd /Users/minibeniitec; mkdir senior_project
	cd /Users/minibeniitec; mkdir senior_project/TheTablespace
	cd /Users/minibeniitec; mkdir senior_project/TheTablespace/TheTablespaceIndex

database-mac:
	psql -f Create_User_Tablespaces_Mac.psql


#Linux Specific	
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

database-linux:
	psql -d postgres -f Create_User_Tablespaces-linux.psql



#General
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

fake:
	psql -d thedatabase -f Create_Fake_Order.psql

ungrant:
	psql -d thedatabase -f Ungrant_All.psql

drop:
	psql -d thedatabase -f Drop_Tables.psql

destroy:
	psql -d postgres -f Drop_User_Tablespaces.psql

endgame:
	cd /Users/minibeniitec/; rm -fr senior_project

push: .git
	git add .
	git commit -m "auto"
	git push origin master
