--Example 35 --Standard Libraries -input/output
-- IO functions:
-- io.close,io.flush,io.input,io.lines,io.open,io.output,io.popen,
-- io.read,io.stderr,io.stdin,io.stdout,io.tmpfile,io.type,io.write,
-- file:close,file:flush,file:lines,file:read,
-- file:seek,file:setvbuf,file:write

print(io.open("file doesn't exist","r"))
local tr=io.open("TransportMineConfig.xml","r")
assert(tr)
for str in tr:lines() do
	print(str)
end
tr:close()

