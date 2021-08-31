pub fn resolution() -> String {
    let r = fibonacci_index(1000);
    r.to_string()
}

#[derive(Clone)]
struct BigNumber {
    n: Vec<u8>,
}

impl BigNumber {
    fn new(number: u64) -> Self {
        let mut n: Vec<u8> = Vec::new();
        number
            .to_string()
            .chars()
            .for_each(|i| n.push(i.to_digit(10).unwrap() as u8));
        n.reverse();
        BigNumber { n }
    }
}

fn fibonacci_index(digitis: u64) -> u64 {
    let mut f1 = BigNumber::new(1);
    let mut f2 = BigNumber::new(1);
    let mut index = 2;
    while f1.n.len() < digitis as usize && f2.n.len() < digitis as usize {
        let aux = sum_big(&f1, &f2);
        f1 = f2.clone();
        f2 = aux;
        index += 1;
    }
    index
}

fn sum_big(number_a: &BigNumber, number_b: &BigNumber) -> BigNumber {
    let min = if number_a.n.len() > number_b.n.len() {
        number_b.n.len()
    } else {
        number_a.n.len()
    };
    let mut n: Vec<u8> = Vec::new();
    let mut carry = 0;
    for i in 0..min {
        let mut sum = number_a.n[i] + number_b.n[i] + carry;
        if sum > 9 {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        n.push(sum);
    }
    let aux = if min < number_a.n.len() {
        &number_a.n
    } else {
        &number_b.n
    };
    for i in aux.iter().skip(min) {
        let mut sum = i + carry;
        if sum > 9 {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        n.push(sum);
    }
    if carry != 0 {
        n.push(1);
    }
    BigNumber { n }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn create_big() {
        let n = vec![9, 9, 9, 9, 9];
        assert_eq!(BigNumber::new(99999).n, n);
        let n = vec![1, 1, 1, 1, 1, 1, 1, 1];
        assert_eq!(BigNumber::new(11111111).n, n);
    }

    #[test]
    fn add_big() {
        let a = BigNumber::new(999);
        let b = BigNumber::new(222);
        assert_eq!(sum_big(&a, &b).n, [1, 2, 2, 1]);
        let a = BigNumber::new(999);
        let b = BigNumber::new(222222);
        let result = BigNumber::new(223221);
        assert_eq!(sum_big(&a, &b).n, result.n);
        let a = BigNumber::new(9999);
        let b = BigNumber::new(1);
        let result = BigNumber::new(10000);
        assert_eq!(sum_big(&a, &b).n, result.n);
        let a = BigNumber::new(233);
        let b = BigNumber::new(377);
        let result = BigNumber::new(610);
        assert_eq!(sum_big(&a, &b).n, result.n);
    }

    #[test]
    fn fib() {
        assert_eq!(fibonacci_index(3), 12);
        assert_eq!(fibonacci_index(4), 17);
    }
}
