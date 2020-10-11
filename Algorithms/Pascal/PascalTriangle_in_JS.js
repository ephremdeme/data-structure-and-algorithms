function generate_new_row(curr_row){
	new_row = [1]
	for(let i=0;i<=curr_row.length-2;i++)
		new_row.push(curr_row[i] + curr_row[i+1])
	new_row.push(1)
	return new_row
}

function generate_pascal_triangle(num_row){
	let triangle = [[1], [1, 1]]
	for(let i=2;i<=num_row-1;i++)
	triangle.push(generate_new_row(triangle[triangle.length-1]))
	
	for(let i=0;i<=num_row-1;i++)
	{
		for(let j=0;j<=num_row-triangle[i].length+1;j++)
		{
			process.stdout.write(" ");
		}
		for(let j=0;j<=triangle[i].length-1;j++)
		{
			process.stdout.write(""+triangle[i][j]+" ");
		}
		process.stdout.write("\n");
	}
}

generate_pascal_triangle(5)