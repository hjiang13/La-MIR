<|subtask_end|>
<|task_end|>
"""  # noqa


def NormalizeTask(task):
    def NormalizeText(text):
        text = text.replace("\\n", " ")
        text = text.replace("\n", " ")
        text = text.replace("\\", "\\\\")
        text = text.replace("'", "\\'")
        return text

    task = NormalizeText(task)
    task = task.replace("|im_end|", "|im_end|</br>")
    task = task.replace("|subtask_end|", "|subtask_end|</br>")
    task = task.replace("<", "&lt;")
    task = task.replace(">", "&gt;")
    return task


def GenerateTask(task):
    task = task.split("----")
    task_id = task[0]
    if task_id == "1":
        task = task[2]
    elif task_id == "3":
        task = task[1]
    elif task_id == "6":
        task = task[15]
    elif task_id == "7":
        task = task[1]
    else:
        task = task[1]
    task = NormalizeTask(task)
    task = task.replace("|im_start|", "<span style='color:blue;font-weight:bold;'>")
    task = task.replace("|im_end|", "</span>")
    task = task.replace("<|subtask_end|>", "</br>")
    task = task.replace("<|im_end|>", "</span>")
    task = task.replace("<|im_start|>", "<span style='color:blue;font-weight:bold;'>")
    task = task.replace("<|subtask_start|>", "</br>")
    task = task.replace("<|task_end|>", "</br>")
    task = task.replace("<|task_start|>", "</br>")
    task = task.replace("</br></br>", "</br>")
    task = task.replace("</br></br>", "</br>")
    task = task.replace("</br></br>", "</br>")
    task = task.replace("</br></br>", "</br>")
    task = task.replace("<em>", "")
    task = task.replace("</em>", "")
    return task


class Task:
    def __init__(self, task_id, task_type, task_data):
        self.task_id = task_id
        self.task_type = task_type
        self.task_data = task_data

    def __str__(self):
        return json.dumps(asdict(self))


def get_task_name(benchmark, suite_name, task_id):
    with open(f"{benchmark}/{suite_name}/{task_id}/{task_id}.json") as f:
        task_name = json.load(f)["task_name"]
    return task_name


def main():
    parser = argparse.ArgumentParser(
        prog="get_task_data",
        description="Get task data from benchmark",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    parser.add_argument("--benchmark", type=str, help="Benchmark folder")
    parser.add_argument("--suite", type=str, help="Suite name")
    parser.add_argument("--task", type=str, help="Task name")
    parser.add_argument("--type", type=str, help="Task type")
    parser.add_argument(
        "--output_file",
        type=str,
        default=None,
        help="Output file for generated tasks",
    )

    args = parser.parse_args()

    benchmark = args.benchmark
    suite_name = args.suite
    task_id = args.task
    task_type = args.type

    task_name = get_task_name(benchmark, suite_name, task_id)

    if task_id == "1":
        task_data = task1
    elif task_id == "3":
        task_data = task3
    elif task_id == "6":
        task_data = task6
    elif task_id == "7":
        task_data = task7
    else:
        task_data = task13

    tasks = []
    for task in task_data:
        task = GenerateTask(task)
        tasks.append(Task(task_id, task_type, task))

    if args.output_file:
        with open(args.output_file, "w") as f:
            f.write("[")
            for task in tasks:
                f.write(str(task))
                if task == tasks[-1]:
                    f.write("\n")
                else:
                    f.write(",\n")
            f.write("]")
    else:
        print("[")
        for task in tasks:
            print(task)
            if task == tasks[-1]:
                print()
            else:
                print(",")
        print("]")


if __name__ == "__main__":
    main()
#undef NDEBUG
#include<assert.h>
int main(){
    assert (strlen("") == 0);
    assert (strlen("x") == 1);
     assert (strlen("asdasnakj") == 9);
}
