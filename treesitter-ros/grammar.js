module.exports = grammar({
  name: 'ros',

  rules: {
    source_file: $ => repeat(
      choice(
        $.comment,
        $.separator,
        $.field_definition,
      )
    ),

    comment: $ => seq($.comment_char, $.comment_string),
    comment_char: $ => '#',
    comment_string: $ => /.*/,

    separator: $ => "---",

    field_definition: $ => seq($.field_type, $.field_name),
    field_type: $ => choice($.builtin_type, $.custom_type, $.array_type),
    builtin_type: $ => choice(
      'bool',
      'int8',
      'uint8',
      'int16',
      'uint16',
      'int32',
      'uint32',
      'int64',
      'uint64',
      'float32',
      'float64',
      'string',
      'time',
      'duration'
    ),
    custom_type: $ => $.identifier,
    array_type: $ => seq(choice($.builtin_type, $.custom_type), '[', ']'),
    field_name: $ => choice($.identifier, $.const_definition),
    const_definition: $ => seq($.const_name, '=', $.const_value),
    const_name: $ => /[A-Z_]+/,
    // TODO: const_value actual regex
    const_value: $ => /.*/,
    identifier: $ => /[a-zA-Z0-9/_]+/,
  }
});
