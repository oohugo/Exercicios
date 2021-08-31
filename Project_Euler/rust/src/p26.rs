pub fn resolution() -> String {
    let primes = get_primes_less(1000);
    let m = primes.iter().map(|i| len_cycles(*i)).max().unwrap();
    (m+1).to_string()
}

fn len_cycles(number: u64) -> u64 {
	let mut base = 10;
	let mut count = 1;
	while base < number {
		base *= 10;
	}
	let first = base % number;
	let mut current = base * first;
	while current != first {
		current *= base;
		current %= number;
		count += 1;
	}
	count
}

fn sum_divisors(max: u64) -> Vec<u64> {
    let mut sum_div: Vec<u64> = Vec::new();
    sum_div.resize_with((max + 1) as usize, Default::default);
    for i in 1..max + 1 {
        for j in ((i + i)..max).step_by(i as usize) {
            sum_div[j as usize] += i;
        }
    }
    sum_div
}

fn get_primes_less(max: u64) -> Vec<u64> {
    sum_divisors(max)
        .iter()
		.enumerate()
        .filter(|(_, i)| **i == 1)
        .map(|(i, _)| i as u64)
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
	fn cycles(){
		assert_eq!(len_cycles(7), 6);
	}

	#[test]
	fn r(){
	assert_eq!(resolution(), 983.to_string());}
}
