# Must be run on machine
all: pregame database tables tuples query

pregame:
	cd /home; mkdir senior_project
	cd /home; mkdir senior_project/TheTablespace
	cd /home; mkdir senior_project/TheTablespaceIndex
	sudo chmod 700 /home/senior_project/*
	sudo chown _postgres:_postgres /home/senior_project/*
	sudo mv /home/senior_project/TheTablespaceIndex /home/senior_project/TheTablespace

database:
	psql -d postgres -f PSQL/Create_User_Tablespaces.psql
	
tables:
	psql -d TheDatabase -f PSQL/Create_Tables.psql

tuples:
	psql -d TheDatabase -f PSQL/Insert_All.psql

query:
	psql -d TheDatabase -f PSQL/Query_All.psql

drop:
	psql -d TheDatabase -f PSQL/Drop_Tables.psql

destroy:
	psql -d TheDatabase -f PSQL/Drop_USer_Tablespaces.psql

push: .git
	git add .
	git commit -m "auto"
	git push origin master
