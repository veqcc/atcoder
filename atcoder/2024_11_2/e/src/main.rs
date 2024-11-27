
struct BinaryIndexedTree {
    n: usize,
    data: Vec<i64>,
}

impl BinaryIndexedTree {
    pub fn new(size: usize) -> Self {
        BinaryIndexedTree {
            n: size,
            data: vec![0; size + 1],
        }
    }

    pub fn add(&mut self, mut index: usize, value: i64) {
        index += 1;
        while index <= self.n {
            self.data[index] += value;
            index += index & (!index + 1);
        }
    }

    fn sum_internal(&self, mut index: usize) -> i64 {
        let mut result = 0;
        while index > 0 {
            result += self.data[index];
            index -= index & (!index + 1);
        }
        result
    }

    pub fn sum(&self, left: usize, right: usize) -> i64 {
        self.sum_internal(right) - self.sum_internal(left)
    }
}

fn main() {
    proconio::input! {
        n: usize,
        m: u64,
        a: [u64; n],
    }

    let mut sum = vec![0; n+1];
    for i in 0..n {
        sum[i+1] = (sum[i] + a[i]) % m;
    }

    let mut ret = 0;

    let mut bit = BinaryIndexedTree::new(m as usize);
    for i in 0..n+1 {
        bit.add(sum[i] as usize, 1);
        ret += m * bit.sum(sum[i] as usize + 1, m as usize) as u64;
    }

    for i in 1..n+1 {
        ret += sum[i] * i as u64;
    }
    for i in 0..n {
        ret -= sum[i] * (n-i) as u64;
    }

    println!("{}", ret);
}