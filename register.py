#!/usr/bin/python36
import cgi

print("content-type: text/html")

cmd=cgi.FieldStorage()

customer=cmd.getvalue('customer')
name=cmd.getvalue('name')
email=cmd.getvalue('email')
psw=cmd.getvalue('psw')
pswrepeat=cmd.getvalue('pswrepeat')

if psw!=pswrepeat:
	print("\n")
	print("""
		Passwords do not match
		<br /><a href='../register.html'>go back</a>
		""")
elif customer=="commuter":
	print("location: ../commuter.html?name="+name+"&email="+email+"&psw="+psw)
	print("\n")
elif customer=="owner":
	print("location: ../owner.html?name="+name+"&email="+email+"&psw="+psw)
	print("\n")
#useless comment
