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

fn get_abundant(max: u64) -> Vec<u64> {
    let div = sum_divisors(max);
    div.iter()
        .enumerate()
        .map(|(i, &v)| -> u64 {
            if (i as u64) < v {
                i as u64
            } else {
                0
            }
        })
        .filter(|&i| i != 0)
        .collect()
}

pub fn resolution() -> u64 {
    const MAX: usize = 28123;
    let abundant_numbers = get_abundant(MAX as u64);
    let mut sum_abundant: Vec<bool> = Vec::new();
    sum_abundant.resize_with(MAX + 1, Default::default);
    let max_abun = abundant_numbers.len();
    for i in 0..max_abun {
        for j in i..max_abun {
            let sum_a = (abundant_numbers[i] + abundant_numbers[j]) as usize;
            if sum_a <= MAX {
                sum_abundant[sum_a] = true;
            }
        }
    }
    let sum = sum_abundant
        .iter()
        .enumerate()
        .map(|(i, &b)| if !b { i as u64 } else { 0 })
        .sum();
    sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_get_abundant() {
        assert_eq!(vec![12], get_abundant(13));
        assert_eq!(vec![12, 18], get_abundant(20));
        assert_eq!(vec![12, 18, 20, 24, 30, 36], get_abundant(40));
    }

    #[test]
    fn test_result() {
        let a = resolution();
        assert_eq!(a - 4179871, 0);
    }
}
