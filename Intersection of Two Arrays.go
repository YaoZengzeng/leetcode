func intersection(nums1 []int, nums2 []int) []int {
    set := make(map[int]bool)
    ans := make(map[int]bool)
    
    for _, n := range nums1 {
        set[n] = true
    }
    
    for _, n := range nums2 {
        if _, ok := set[n]; ok {
            ans[n] = true
        }
    }
    
    ret := []int{}
    for n, _ := range ans {
        ret = append(ret, n)
    }
    
    return ret
}
