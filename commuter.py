#!/usr/bin/python36

import subprocess,os,cgi

#header
print("content-type: text/html")

cmd=cgi.FieldStorage()

customer=cmd.getvalue('customer')
name=cmd.getvalue('name')
email=cmd.getvalue('email')
psw=cmd.getvalue('psw')
psw_repeat=cmd.getvalue('psw-repeat')

if psw!=psw_repeat:
	print("\n")
	print("""
		Passwords do not match
		<br /><a href='register.html'>go back</a>
		""")
elif customer=="commuter":
	print("location: commuter.html?name="+name+"?email="+email+"?psw="+psw)
	print("\n")
elif customer=="owner":
	print("location: owner.html?name="+name+"?email="+email+"?psw="+psw)
	print("\n")
