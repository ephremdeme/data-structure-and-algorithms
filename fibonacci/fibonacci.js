function fibonacci_series (number_of_terms) 
{
	// when there is only 1 term left then the first terms are to be returned
  if (number_of_terms === 1) 
  {
    return [0, 1];
  } 
  else 
  {
		// recursive call to its own self to get the last term
		let generated_series = fibonacci_series (number_of_terms - 1);
		// current term is the sum of the previous two terms
		generated_series.push(generated_series[generated_series.length - 1] + generated_series[generated_series.length - 2]);
		// returns the generated sequence
    return generated_series;
  }
};

// call the generate the sequence with the parameter indicating the number of terms upto which the sequence is to be generated
fibonacci_series(8);
