local n = io.read("*n")
local c
--print(n)
for l = 1,n do
  c=1
  --print(c)
  for x = 1,l do
    io.write(c," ")
    c=(c*(l-x)/x)
  end
  io.write("\n")
end

