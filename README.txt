Welcome to the Database.

Before Starting:

	1. In Create_User_TableSpaces.psql you must change the owner.
	2. Linux - This version does not work in MacOS given the default directories.
		Note: This will work in SELinux.
	3. MacOS - This version works assuming you change the default directories.

Makefile:

	make
		The make command automatically create all tablespaces, tables, 
		and insert default data.

	make drop
		Drop tables
	
	make destroy
		Destroy the database and tables paces. 
		Note: This cannot be undone.