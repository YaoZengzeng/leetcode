func intersect(nums1 []int, nums2 []int) []int {
    set := make(map[int]int)
    ans := make(map[int]int)
    
    for _, n := range nums1 {
        if _, ok := set[n]; !ok {
            set[n] = 1
        } else {
            set[n]++
        }
    }
    
    for _, n := range nums2 {
        if _, ok := set[n]; ok {
            if _, ok := ans[n]; !ok {
                ans[n] = 1
            } else {
                ans[n]++
            }
        }
    }
    
    ret := []int{}
    for n, t := range ans {
        if set[n] < t {
            t = set[n]
        }
        for i := 0; i < t; i++ {
            ret = append(ret, n)
        }
    }
    
    return ret
}
