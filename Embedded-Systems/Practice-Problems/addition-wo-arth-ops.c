uint32_t addTwoValues(uint32_t a, uint32_t b){
    uint32_t res = (a ^ b);
    uint32_t carry_out = (a & b) << 1u;

    while (carry_out){
        uint32_t res_mask = res;
        res = carry_out ^ res_mask; //addition without carry
        carry_out = ((res_mask & carry_out) << 1u); //create the carry mask
    }

    return res;
}