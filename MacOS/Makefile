# Must be run on machine
all: database tables tuples query

pregame:
	cd /Users/minibeniitec; mkdir senior_project
	cd /Users/minibeniitec; mkdir senior_project/TheTablespace
	cd /Users/minibeniitec; mkdir senior_project/TheTablespaceIndex
	mv /Users/minibeniitece/senior_project/TheTablespaceIndex /Users/minibeniitec/senior_project/TheTablespace

database:
	psql -f Create_User_Tablespaces.psql
	
tables:
	psql -d thedatabase -f Create_Tables.psql

tuples:
	psql -d thedatabase -f Insert_All.psql

grant:
	psql -d thedatabase -f Grant_All.psql

query:
	psql -d thedatabase -f Query_All.psql

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
