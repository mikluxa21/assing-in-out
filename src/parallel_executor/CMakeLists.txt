set(
        PROJECT_NAME parallel_executor
)

set(HDRS
        ParallelClientExecutor.h
)
set(SRCS
        src/ParallelClientExecutor.cpp
)
set(
        LIB_NAME lib_parallel_executor
)
add_library(${LIB_NAME}
        OBJECT ${SRCS} ${HDRS}
)
