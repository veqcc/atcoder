use proconio::input;
use std::collections::BinaryHeap;
 
fn main() {
    input! {
        n: usize,
        k: usize,
        a: [i64; n]
    }

    let mut heap = BinaryHeap::new();
    for i in 0..n {
        heap.push(-a[i]);
    }

    let mut prev = 0;
    for _ in 0..k {
        loop {
            let top = heap.pop();
            match top {
                Some(elem) => {
                    if prev != elem {
                        for i in 0..n {
                            heap.push(elem - a[i]);
                        }
                        prev = elem;
                        break;
                    }
                },
                _ => ()
            }
        }
    }
    
    println!("{}", -prev);
}