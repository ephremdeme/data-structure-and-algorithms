-- Problem : To print Pascal's Triangle


local n = io.read("*n")
local c
for l = 1,n do
  c=1
  for x = 1,l do
    io.write(c," ")
    c=(c*(l-x)/x)
  end
  io.write("\n")
end

