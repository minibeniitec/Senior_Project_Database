Welcome to the Database.

Before continuing, know that the following information is incomplete and is outdated. 
In order to properly complete the database installation, you must verify that all the
folders are created before hand to match the listed directories as well as configure
Postgres so that the account being ran has administrative privileges. Whatever account 
is being, change the Create_User_Tablespaces.psql file to reflect that the owner of 
everything will be the account you are under.

In order to run the C file you must also reconfigure the C++ file to reflect the new
ownership of the file as well.



Step 1: Run this commmand in this directory

	cd PSQL; vim Create_User_Tablespaces.psql



Step 2: Modify the file Create_User_Tablespaces.psql

	Where it lists the directory, all you have to do is modify the three
	instances of the file path to match your username and desktop patch.

	Ex: 
		Before: /User/Minibeniitec/Desktop/Senior_Project...
		After:  /home/egonzalez/Desktop/Senior_Project...


Step 3: Run make

	The make command and it will compile and run the program and clean 
	up after automatically.

	Within the program you can follow the menu. You can build the db, 
	automatically fill it with fake data, and destroy it within the 
	program.
