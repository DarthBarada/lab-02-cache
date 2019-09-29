Каждый проход массив заполнялся рандомными числами до 1000
```investigation:
        travel_order:front pass
        experiments:
         - experiment:
            number: 1
            input_data:
              buffer_size: "1 mb"
            results:
              duration: "4244 ms"
         - experiment:
            number: 2
            input_data:
              buffer_size: "2 mb"
            results:
              duration: "8397 ms"
         - experiment:
            number: 3
            input_data:
              buffer_size: "4 mb"
            results:
              duration: "16805 ms"
         - experiment:
            number: 4
            input_data:
              buffer_size: "8 mb"
            results:
              duration: "33638 ms"
         - experiment:
            number: 5
            input_data:
              buffer_size: "12 mb"
            results:
              duration: "50446 ms"
investigation:
        travel_order:reverse pass
        experiments:
         - experiment:
            number: 1
            input_data:
              buffer_size: "1 mb"
            results:
              duration: "4091 ms"
         - experiment:
            number: 2
            input_data:
              buffer_size: "2 mb"
            results:
              duration: "8181 ms"
         - experiment:
            number: 3
            input_data:
              buffer_size: "4 mb"
            results:
              duration: "16533 ms"
         - experiment:
            number: 4
            input_data:
              buffer_size: "8 mb"
            results:
              duration: "32901 ms"
         - experiment:
            number: 5
            input_data:
              buffer_size: "12 mb"
            results:
              duration: "49381 ms"
investigation:
        travel_order:random pass
        experiments:
         - experiment:
            number: 1
            input_data:
              buffer_size: "1 mb"
            results:
              duration: "4232 ms"
         - experiment:
            number: 2
            input_data:
              buffer_size: "2 mb"
            results:
              duration: "8490 ms"
         - experiment:
            number: 3
            input_data:
              buffer_size: "4 mb"
            results:
              duration: "17021 ms"
         - experiment:
            number: 4
            input_data:
              buffer_size: "8 mb"
            results:
              duration: "33693 ms"
         - experiment:
            number: 5
            input_data:
              buffer_size: "12 mb"
            results:
              duration: "50467 ms"
