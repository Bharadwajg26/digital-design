module logic_comparision {

	input wire x,
	input wire x,
	input wire x,
	output wire r1
	output wire r2
	output wire assign_result
};

// Intermediate signals
	assign r1 = x || (x && y);
	assign r2 = x || (x && Y) || (y && z);
	
	//ooutput assignment
	assignment = (r1 == r2);
endmodule