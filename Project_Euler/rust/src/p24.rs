use itertools::Itertools;

fn decimal_to_factorial_system(number: u64) -> String {
    let mut reminder: Vec<u64> = vec![0];
    let mut i = 2;
    let mut n = number;
    while n > i {
        reminder.push(n % i);
        n /= i;
        i += 1;
    }
    reminder.push(n);
    let factorial_number = reminder
        .iter()
        .rev()
        .map(ToString::to_string)
        .reduce(|a, b| a + &b)
        .unwrap();
    factorial_number
}

fn permutation(base: Vec<u64>, list: Vec<char>) -> Vec<char> {
    let base = base.iter().map(|i| *i as usize);
    let mut list = list;
    let mut p: Vec<char> = Vec::new();
    for i in base {
        p.push(list[i]);
        list.remove(i);
        if list.is_empty() {
            break;
        }
    }
    if !list.is_empty() {
        list.into_iter().for_each(|i| p.push(i));
    }
    p
}

pub fn resolution() -> String {
    let digits = "0123456789".chars().collect_vec();
    let factorial_number = decimal_to_factorial_system(1000000 - 1);
    let factorial_number: Vec<u64> = factorial_number
        .chars()
        .map(|i| i.to_digit(10).unwrap() as u64)
        .collect();
    let p = permutation(factorial_number, digits);
    p.iter()
        .map(|i| i.to_string())
        .reduce(|a, b| a + &b)
        .unwrap()
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn decimal_to_fac() {
        assert_eq!(decimal_to_factorial_system(463), "341010");
        assert_eq!(decimal_to_factorial_system(719), "543210");
    }

    #[test]
    fn get_permutation() {
        let base = "4041000"
            .chars()
            .map(|i| i.to_digit(10).unwrap() as u64)
            .collect();
        let list = vec!['0', '1', '2', '3', '4', '5', '6'];
        let result = vec!['4', '0', '6', '2', '1', '3', '5'];
        assert_eq!(permutation(base, list), result);
    }
}
