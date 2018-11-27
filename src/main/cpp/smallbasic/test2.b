print "This program demonstrates all commands."
for x = 1 to 10
  print x, x / 2, x, x*x
next

print "Calling subruntine"
gosub 300
print "Subroutine returned okay"

input "Input. Enter a number between 1&10: ";h
if h < 11 then goto 200
print "12 - 4 / 2 should be 10=";12 - 4 / 2
print "Printing the number 100"
print 100
200 a = 100 / 2
print "a should be 50 and greater then 10"
if a > 10 then print "Success. a > 10 worked."
print a
print a + 34
input "There should be a question mark for this input ",y
print "testing else"
a = 10
if a < 10 then print "else failed" else print "Else okay"

input "Enter your name: ";a$
print "You entered ";a$
if a$="lee" then print "You entered my name!" else print "Glad to meet you"

print "====== === == = =  ="
print "All tests completed"
end
300 print "Subroutine ented okay"
return

