use proconio::input;
use std::collections::VecDeque;

fn main() {
    input! {
        n: usize,
        mut a: [usize; n],
    }

    let mut sum = a.clone();
    for i in 0..n {
        sum[i] = 0;
    }
    for i in 0..n {
        sum[a[i] - 1] += 1;
    }

    let mut q = VecDeque::new();
    for i in 0..n {
        if sum[i] == 0 {
            q.push_back(i);
        }
    }

    let mut ans = n;
    while let Some(idx) = q.pop_front() {
        ans -= 1;
        sum[a[idx] - 1] -= 1;
        if sum[a[idx] - 1] == 0 {
            q.push_back(a[idx] - 1);
        }
    }

    println!("{}", ans);
}