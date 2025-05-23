<|im_end|>
        """.strip("\n")

    def test_parse_task_code(self):
        task = parse_task(self.task_string)
        code = task.code
        assert task.language == "cpp"
        assert task.language_version == "136"
        assert code.startswith("b'; ModuleID = \'../../Human_xBenchmarks_164/CPP_136/CPP_136.cpp\'\n")