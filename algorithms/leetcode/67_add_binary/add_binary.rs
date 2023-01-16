fn add_binary(a: String, b: String) -> String {
    let mut a = String::from(a);
    let mut b = String::from(b);
    let mut result = String::new();
    let mut carry = false;
    loop {
        let l = a.pop();
        let r = b.pop();
        match (l, r) {
            (Some(aa), Some(bb)) => {
                if aa == '1' && bb == '1' {
                    if carry {
                        result.push('1');
                    } else {
                        result.push('0');
                        carry = true
                    }
                } else if aa == '0' && bb == '0' {
                    if carry {
                        result.push('1');
                    } else {
                        result.push('0');
                    }
                    carry = false;
                } else {
                    if carry {
                        result.push('0');
                    } else {
                        result.push('1');
                    }
                }
            },
            (None, Some(bb)) => {
                if bb == '1' {
                    if carry {
                        result.push('0');
                    } else {
                        result.push('1');
                    }
                } else {
                    if carry {
                        result.push('1');
                        carry = false;
                    } else {
                        result.push('0');
                    }
                }
            },
            (Some(aa), None) => {
                if aa == '1' {
                    if carry {
                        result.push('0');
                    } else {
                        result.push('1');
                    }
                } else {
                    if carry {
                        result.push('1');
                        carry = false;
                    } else {
                        result.push('0');
                    }
                }
            },
            (None, None) => {
                break;
            },
        }
    }

    if carry {
        result.push('1');
    }

    result.chars().rev().collect::<String>()
}

fn main() {
    assert_eq!(add_binary("11".to_string(), "1".to_string()), "100");
    assert_eq!(add_binary("1010".to_string(), "1011".to_string()), "10101");
    assert_eq!(add_binary("101111".to_string(), "10".to_string()), "110001");
}
