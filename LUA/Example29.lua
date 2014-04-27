--Example 29 --variable scoping and functions.

b="global"
function myfunc()
	local b="local variable"
	a="global variable"
	print(a,b)
end

myfunc()
print(a,b)
