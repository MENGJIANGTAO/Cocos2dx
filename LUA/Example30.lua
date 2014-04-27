--Example 30 --Formatted printting

function printf(fmt,...)
	io.write(string.format(fmt,...))
end

printf("Hello %s from %s on %s \n","there",_VERSION,os.date())
printf("my name is %s,and i'am %d years old.","mengjiangtao",27)
