//
// Created by Dawid on 03.01.2016.
//

#include <format.h>
#include <coro.h>

coro_context ctx, mainctx;
coro_stack stack;

void coro_body(void *arg) {
    fmt::printf("OK\n");
    coro_transfer(&ctx, &mainctx);
    fmt::printf("Back in coro\n");
    coro_transfer(&ctx, &mainctx);
}
int main(int argc, char **argv) {
    coro_create(&mainctx, NULL, NULL, NULL, 0);
    coro_stack_alloc(&stack, 0);
    coro_create(&ctx, coro_body, NULL, stack.sptr, stack.ssze);
    fmt::printf("Created a coro\n");
    coro_transfer(&mainctx, &ctx);
    fmt::printf("Back in main\n");
    coro_transfer(&mainctx, &ctx);
    fmt::printf("Back in main again\n");
    return 0;
}