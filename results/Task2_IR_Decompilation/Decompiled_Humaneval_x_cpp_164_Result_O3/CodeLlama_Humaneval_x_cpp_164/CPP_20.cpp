<|im_start|>system

        <|im_end|>
<|im_start|>user

        Your output should be written here.
        <|im_end|>
<|im_start|>system

        Your output should be written here.
        <|im_end|>
"""


class XSumConverter(DatasetConverter):
    def __init__(self, text_format='reference', *args, **kwargs):
        self.text_format = text_format
        self.has_time_limit = False
        super().__init__(*args, **kwargs)

    def _clean(self, text: str):
        text = text.strip()
        if text.startswith('<|im_start|>'):
            text = text[len('<|im_start|>'):]
        if text.endswith('<|im_end|>'):
            text = text[:-len('<|im_end|>')]
        text = text.strip()
        if self.text_format == 'reference':
            text = '# ' + text
        elif self.text_format == 'user':
            text = '>' + text
        elif self.text_format == 'system':
            text = '< ' + text
        else:
            raise ValueError(f'Unknown text format: {self.text_format}')
        return text

    def _convert_example(self, example: Dict[str, Any]):
        # source
        source = self._clean(example['source'])
        # target
        target = self._clean(example['target'])
        # reference
        if 'reference' in example:
            reference = self._clean(example['reference'])
        else:
            reference = None
        # time_limit
        if 'time_limit' in example:
            if self.has_time_limit:
                time_limit = example['time_limit']
            else:
                time_limit = None
        else:
            time_limit = None
        return source, target, reference, time_limit


class XSum(BaseDataset):
    """
    The XSum dataset.
    """
    def __init__(self,
                 name='xsum',
                 language='en',
                 test_language='en',
                 text_format='reference',
                 task_code='001'):
        super().__init__(
            name,
            language=language,
            test_language=test_language,
            task_code=task_code)
        self.text_format = text_format
        self.has_time_limit = False

    @property
    def metrics(self):
        return ['rouge']

    @property
    def metric_configs(self):
        return [{"reference-language": self.test_language}]

    def _load_raw_dataset(self, path: str, stage: str, **kwargs):
        if stage == 'train':
            path = os.path.join(path, 'train.jsonl')
            return load_dataset('json', data_files=path)['train']
        else:
            path = os.path.join(path, 'val.jsonl')
            return load_dataset('json', data_files=path)['train']

    def _load_train_source(self, path: str) -> List[str]:
        """
        The training data of xsum is not in the form of a source, target pair.
        Instead, it has a source, a target, and a reference in each line.
        We take the source and the reference as training, and the target as the
        validation set.
        """
        raw_source = super()._load_train_source(path)
        raw_reference = super()._load_train_target(path)
        return [r + '\n' + s for s, r in zip(raw_source, raw_reference)]

    def _load_train_target(self, path: str) -> List[str]:
        raw_target = super()._load_train_target(path)
        return raw_target

    def _load_dev_source(self, path: str) -> List[str]:
        raw_source = super()._load_dev_source(path)
        raw_reference = super()._load_dev_target(path)
        return [r + '\n' + s for s, r in zip(raw_source, raw_reference)]

    def _load_dev_target(self, path: str) -> List[str]:
        raw_target = super()._load_dev_target(path)
        return raw_target

    def _convert_train_example(self, example: Dict[str, Any]):
        return self._convert_example(example, 'train')

    def _convert_dev_example(self, example: Dict[str, Any]):
        return self._convert_example(example, 'dev')

    def _convert_example(self, example: Dict[str, Any], stage: str):
        if stage == 'train':
            source = example['source']
            target = example['target']
            reference = example['reference']
            source = source + '\n# ' + reference
        elif stage == 'dev':
            source = example['source']
            target = example['target']
            reference = example['reference']
            source = source + '\n# ' + reference
        else:
            raise ValueError(f'Unknown stage: {stage}')
        return source, target