#!/usr/bin/python

import cgi,os

print("content-type: text/html")
print("\n")

cmd=cgi.FieldStorage()

platenumber=cgi.getvalue('platenumber')
x=cgi.getvalue('x')
y=cgi.getvalue('y')
r=cgi.getvalue('r')
name=cgi.getvalue('name')

days = []
start = []
end = []
k=0

for i in range(7):
	if cgi.getvalue("day"+i)=="on":
		days[k]=i
		start[k]=cgi.getvalue("start"+i)
		end[k]=cgi.getvalue("end"+i)
		k=k+1

argument = "1 "+platenumber+" "+x+" "+y+" "+r+" "+name+" "+k;

for i in range(k):
	argument=argument+" "+days[i]+" "+start[i]+" "+end[i]

os.system("g++ carpool.cpp -std="+argument)
