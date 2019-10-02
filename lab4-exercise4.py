#!/usr/bin/env python3
import sqlite3
#some initial data
ttime = 'now';
tdate = '2014-01-05';
temperature = 0.0;
zone = 4
#connect to database file
dbconnect = sqlite3.connect("temperature.db");
#If we want to access columns by name we need to set
#row_factory to sqlite3.Row class
dbconnect.row_factory = sqlite3.Row;
#now we create a cursor to work with db
cursor = dbconnect.cursor();
for i in range(10):
    #execute insert statement
    zone += 1;
    temperature += 1.1;
    cursor.execute('''insert into temps values (?, ?, ?, ?)''',
    (tdate, ttime, zone, temperature));
dbconnect.commit();
#execute simple select statement
cursor.execute('SELECT * FROM temps');
#print data
for row in cursor:
   # print(row['ttime'],row['tdate'],row['zone'], row['temperature'] );
#close the connection
dbconnect.close();

#_________________________________________


# connecting to file
dbconnect2 = sqlite3.connect("sensors.db");
# to access  columns by name
dbconnect2.row_factory = sqlite3.Row;
# now to create the cursor
cursor2 = dbconnect2.cursor();

# now to  select only the  specific components with the key word
cursor2.execute('SELECT * FROM sensors WHERE zone == "kitchen");

for row in cursor2:
	print(row['sensorID'], row['type'], row['zone']);

dbconnect2.close;
