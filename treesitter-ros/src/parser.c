#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 19
#define LARGE_STATE_COUNT 8
#define SYMBOL_COUNT 34
#define ALIAS_COUNT 0
#define TOKEN_COUNT 24
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  sym_comment_char = 1,
  sym_comment_string = 2,
  sym_separator = 3,
  anon_sym_bool = 4,
  anon_sym_int8 = 5,
  anon_sym_uint8 = 6,
  anon_sym_int16 = 7,
  anon_sym_uint16 = 8,
  anon_sym_int32 = 9,
  anon_sym_uint32 = 10,
  anon_sym_int64 = 11,
  anon_sym_uint64 = 12,
  anon_sym_float32 = 13,
  anon_sym_float64 = 14,
  anon_sym_string = 15,
  anon_sym_time = 16,
  anon_sym_duration = 17,
  anon_sym_LBRACK = 18,
  anon_sym_RBRACK = 19,
  anon_sym_EQ = 20,
  sym_const_name = 21,
  sym_const_value = 22,
  sym_identifier = 23,
  sym_source_file = 24,
  sym_comment = 25,
  sym_field_definition = 26,
  sym_field_type = 27,
  sym_builtin_type = 28,
  sym_custom_type = 29,
  sym_array_type = 30,
  sym_field_name = 31,
  sym_const_definition = 32,
  aux_sym_source_file_repeat1 = 33,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_comment_char] = "comment_char",
  [sym_comment_string] = "comment_string",
  [sym_separator] = "separator",
  [anon_sym_bool] = "bool",
  [anon_sym_int8] = "int8",
  [anon_sym_uint8] = "uint8",
  [anon_sym_int16] = "int16",
  [anon_sym_uint16] = "uint16",
  [anon_sym_int32] = "int32",
  [anon_sym_uint32] = "uint32",
  [anon_sym_int64] = "int64",
  [anon_sym_uint64] = "uint64",
  [anon_sym_float32] = "float32",
  [anon_sym_float64] = "float64",
  [anon_sym_string] = "string",
  [anon_sym_time] = "time",
  [anon_sym_duration] = "duration",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_EQ] = "=",
  [sym_const_name] = "const_name",
  [sym_const_value] = "const_value",
  [sym_identifier] = "identifier",
  [sym_source_file] = "source_file",
  [sym_comment] = "comment",
  [sym_field_definition] = "field_definition",
  [sym_field_type] = "field_type",
  [sym_builtin_type] = "builtin_type",
  [sym_custom_type] = "custom_type",
  [sym_array_type] = "array_type",
  [sym_field_name] = "field_name",
  [sym_const_definition] = "const_definition",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_comment_char] = sym_comment_char,
  [sym_comment_string] = sym_comment_string,
  [sym_separator] = sym_separator,
  [anon_sym_bool] = anon_sym_bool,
  [anon_sym_int8] = anon_sym_int8,
  [anon_sym_uint8] = anon_sym_uint8,
  [anon_sym_int16] = anon_sym_int16,
  [anon_sym_uint16] = anon_sym_uint16,
  [anon_sym_int32] = anon_sym_int32,
  [anon_sym_uint32] = anon_sym_uint32,
  [anon_sym_int64] = anon_sym_int64,
  [anon_sym_uint64] = anon_sym_uint64,
  [anon_sym_float32] = anon_sym_float32,
  [anon_sym_float64] = anon_sym_float64,
  [anon_sym_string] = anon_sym_string,
  [anon_sym_time] = anon_sym_time,
  [anon_sym_duration] = anon_sym_duration,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_const_name] = sym_const_name,
  [sym_const_value] = sym_const_value,
  [sym_identifier] = sym_identifier,
  [sym_source_file] = sym_source_file,
  [sym_comment] = sym_comment,
  [sym_field_definition] = sym_field_definition,
  [sym_field_type] = sym_field_type,
  [sym_builtin_type] = sym_builtin_type,
  [sym_custom_type] = sym_custom_type,
  [sym_array_type] = sym_array_type,
  [sym_field_name] = sym_field_name,
  [sym_const_definition] = sym_const_definition,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_comment_char] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_string] = {
    .visible = true,
    .named = true,
  },
  [sym_separator] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uint8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uint16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uint32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uint64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_string] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_time] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_duration] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_const_name] = {
    .visible = true,
    .named = true,
  },
  [sym_const_value] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_field_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_field_type] = {
    .visible = true,
    .named = true,
  },
  [sym_builtin_type] = {
    .visible = true,
    .named = true,
  },
  [sym_custom_type] = {
    .visible = true,
    .named = true,
  },
  [sym_array_type] = {
    .visible = true,
    .named = true,
  },
  [sym_field_name] = {
    .visible = true,
    .named = true,
  },
  [sym_const_definition] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(6);
      if (lookahead == '#') ADVANCE(7);
      if (lookahead == '-') ADVANCE(2);
      if (lookahead == '=') ADVANCE(27);
      if (lookahead == '[') ADVANCE(25);
      if (lookahead == ']') ADVANCE(26);
      if (lookahead == 'b') ADVANCE(56);
      if (lookahead == 'd') ADVANCE(67);
      if (lookahead == 'f') ADVANCE(50);
      if (lookahead == 'i') ADVANCE(54);
      if (lookahead == 's') ADVANCE(64);
      if (lookahead == 't') ADVANCE(45);
      if (lookahead == 'u') ADVANCE(48);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(28);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 1:
      if (lookahead == '-') ADVANCE(10);
      END_STATE();
    case 2:
      if (lookahead == '-') ADVANCE(1);
      END_STATE();
    case 3:
      if (lookahead == '[') ADVANCE(25);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(28);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 4:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 5:
      if (eof) ADVANCE(6);
      if (lookahead == '#') ADVANCE(7);
      if (lookahead == '-') ADVANCE(2);
      if (lookahead == 'b') ADVANCE(56);
      if (lookahead == 'd') ADVANCE(67);
      if (lookahead == 'f') ADVANCE(50);
      if (lookahead == 'i') ADVANCE(54);
      if (lookahead == 's') ADVANCE(64);
      if (lookahead == 't') ADVANCE(45);
      if (lookahead == 'u') ADVANCE(48);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_comment_char);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_comment_string);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(9);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_comment_string);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(9);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_separator);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_bool);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_int8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_uint8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_int16);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_uint16);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_int32);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_uint32);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_int64);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_uint64);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_float32);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_float64);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_string);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_time);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_duration);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_const_name);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(28);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_const_value);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1') ADVANCE(39);
      if (lookahead == '3') ADVANCE(32);
      if (lookahead == '6') ADVANCE(36);
      if (lookahead == '8') ADVANCE(12);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1') ADVANCE(40);
      if (lookahead == '3') ADVANCE(33);
      if (lookahead == '6') ADVANCE(37);
      if (lookahead == '8') ADVANCE(13);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '2') ADVANCE(16);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '2') ADVANCE(17);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '2') ADVANCE(20);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '3') ADVANCE(34);
      if (lookahead == '6') ADVANCE(38);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '4') ADVANCE(18);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '4') ADVANCE(19);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '4') ADVANCE(21);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '6') ADVANCE(14);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '6') ADVANCE(15);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(66);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(63);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(23);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(22);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(51);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(52);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(58);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(55);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(11);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(59);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(43);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(44);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(24);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(62);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(65);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(57);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(49);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(53);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(42);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(41);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(46);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(30);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(35);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(61);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(31);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(47);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(60);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_identifier);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 5},
  [2] = {.lex_state = 5},
  [3] = {.lex_state = 5},
  [4] = {.lex_state = 5},
  [5] = {.lex_state = 5},
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 5},
  [8] = {.lex_state = 3},
  [9] = {.lex_state = 3},
  [10] = {.lex_state = 3},
  [11] = {.lex_state = 3},
  [12] = {.lex_state = 3},
  [13] = {.lex_state = 3},
  [14] = {.lex_state = 8},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 4},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_comment_char] = ACTIONS(1),
    [sym_separator] = ACTIONS(1),
    [anon_sym_bool] = ACTIONS(1),
    [anon_sym_int8] = ACTIONS(1),
    [anon_sym_uint8] = ACTIONS(1),
    [anon_sym_int16] = ACTIONS(1),
    [anon_sym_uint16] = ACTIONS(1),
    [anon_sym_int32] = ACTIONS(1),
    [anon_sym_uint32] = ACTIONS(1),
    [anon_sym_int64] = ACTIONS(1),
    [anon_sym_uint64] = ACTIONS(1),
    [anon_sym_float32] = ACTIONS(1),
    [anon_sym_float64] = ACTIONS(1),
    [anon_sym_string] = ACTIONS(1),
    [anon_sym_time] = ACTIONS(1),
    [anon_sym_duration] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [sym_const_name] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(15),
    [sym_comment] = STATE(2),
    [sym_field_definition] = STATE(2),
    [sym_field_type] = STATE(8),
    [sym_builtin_type] = STATE(11),
    [sym_custom_type] = STATE(11),
    [sym_array_type] = STATE(12),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_comment_char] = ACTIONS(5),
    [sym_separator] = ACTIONS(7),
    [anon_sym_bool] = ACTIONS(9),
    [anon_sym_int8] = ACTIONS(9),
    [anon_sym_uint8] = ACTIONS(9),
    [anon_sym_int16] = ACTIONS(9),
    [anon_sym_uint16] = ACTIONS(9),
    [anon_sym_int32] = ACTIONS(9),
    [anon_sym_uint32] = ACTIONS(9),
    [anon_sym_int64] = ACTIONS(9),
    [anon_sym_uint64] = ACTIONS(9),
    [anon_sym_float32] = ACTIONS(9),
    [anon_sym_float64] = ACTIONS(9),
    [anon_sym_string] = ACTIONS(9),
    [anon_sym_time] = ACTIONS(9),
    [anon_sym_duration] = ACTIONS(9),
    [sym_identifier] = ACTIONS(11),
  },
  [2] = {
    [sym_comment] = STATE(3),
    [sym_field_definition] = STATE(3),
    [sym_field_type] = STATE(8),
    [sym_builtin_type] = STATE(11),
    [sym_custom_type] = STATE(11),
    [sym_array_type] = STATE(12),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [sym_comment_char] = ACTIONS(5),
    [sym_separator] = ACTIONS(15),
    [anon_sym_bool] = ACTIONS(9),
    [anon_sym_int8] = ACTIONS(9),
    [anon_sym_uint8] = ACTIONS(9),
    [anon_sym_int16] = ACTIONS(9),
    [anon_sym_uint16] = ACTIONS(9),
    [anon_sym_int32] = ACTIONS(9),
    [anon_sym_uint32] = ACTIONS(9),
    [anon_sym_int64] = ACTIONS(9),
    [anon_sym_uint64] = ACTIONS(9),
    [anon_sym_float32] = ACTIONS(9),
    [anon_sym_float64] = ACTIONS(9),
    [anon_sym_string] = ACTIONS(9),
    [anon_sym_time] = ACTIONS(9),
    [anon_sym_duration] = ACTIONS(9),
    [sym_identifier] = ACTIONS(11),
  },
  [3] = {
    [sym_comment] = STATE(3),
    [sym_field_definition] = STATE(3),
    [sym_field_type] = STATE(8),
    [sym_builtin_type] = STATE(11),
    [sym_custom_type] = STATE(11),
    [sym_array_type] = STATE(12),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(17),
    [sym_comment_char] = ACTIONS(19),
    [sym_separator] = ACTIONS(22),
    [anon_sym_bool] = ACTIONS(25),
    [anon_sym_int8] = ACTIONS(25),
    [anon_sym_uint8] = ACTIONS(25),
    [anon_sym_int16] = ACTIONS(25),
    [anon_sym_uint16] = ACTIONS(25),
    [anon_sym_int32] = ACTIONS(25),
    [anon_sym_uint32] = ACTIONS(25),
    [anon_sym_int64] = ACTIONS(25),
    [anon_sym_uint64] = ACTIONS(25),
    [anon_sym_float32] = ACTIONS(25),
    [anon_sym_float64] = ACTIONS(25),
    [anon_sym_string] = ACTIONS(25),
    [anon_sym_time] = ACTIONS(25),
    [anon_sym_duration] = ACTIONS(25),
    [sym_identifier] = ACTIONS(28),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(31),
    [sym_comment_char] = ACTIONS(31),
    [sym_separator] = ACTIONS(31),
    [anon_sym_bool] = ACTIONS(33),
    [anon_sym_int8] = ACTIONS(33),
    [anon_sym_uint8] = ACTIONS(33),
    [anon_sym_int16] = ACTIONS(33),
    [anon_sym_uint16] = ACTIONS(33),
    [anon_sym_int32] = ACTIONS(33),
    [anon_sym_uint32] = ACTIONS(33),
    [anon_sym_int64] = ACTIONS(33),
    [anon_sym_uint64] = ACTIONS(33),
    [anon_sym_float32] = ACTIONS(33),
    [anon_sym_float64] = ACTIONS(33),
    [anon_sym_string] = ACTIONS(33),
    [anon_sym_time] = ACTIONS(33),
    [anon_sym_duration] = ACTIONS(33),
    [sym_identifier] = ACTIONS(33),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_comment_char] = ACTIONS(35),
    [sym_separator] = ACTIONS(35),
    [anon_sym_bool] = ACTIONS(37),
    [anon_sym_int8] = ACTIONS(37),
    [anon_sym_uint8] = ACTIONS(37),
    [anon_sym_int16] = ACTIONS(37),
    [anon_sym_uint16] = ACTIONS(37),
    [anon_sym_int32] = ACTIONS(37),
    [anon_sym_uint32] = ACTIONS(37),
    [anon_sym_int64] = ACTIONS(37),
    [anon_sym_uint64] = ACTIONS(37),
    [anon_sym_float32] = ACTIONS(37),
    [anon_sym_float64] = ACTIONS(37),
    [anon_sym_string] = ACTIONS(37),
    [anon_sym_time] = ACTIONS(37),
    [anon_sym_duration] = ACTIONS(37),
    [sym_identifier] = ACTIONS(37),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(39),
    [sym_comment_char] = ACTIONS(39),
    [sym_separator] = ACTIONS(39),
    [anon_sym_bool] = ACTIONS(41),
    [anon_sym_int8] = ACTIONS(41),
    [anon_sym_uint8] = ACTIONS(41),
    [anon_sym_int16] = ACTIONS(41),
    [anon_sym_uint16] = ACTIONS(41),
    [anon_sym_int32] = ACTIONS(41),
    [anon_sym_uint32] = ACTIONS(41),
    [anon_sym_int64] = ACTIONS(41),
    [anon_sym_uint64] = ACTIONS(41),
    [anon_sym_float32] = ACTIONS(41),
    [anon_sym_float64] = ACTIONS(41),
    [anon_sym_string] = ACTIONS(41),
    [anon_sym_time] = ACTIONS(41),
    [anon_sym_duration] = ACTIONS(41),
    [sym_identifier] = ACTIONS(41),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym_comment_char] = ACTIONS(43),
    [sym_separator] = ACTIONS(43),
    [anon_sym_bool] = ACTIONS(45),
    [anon_sym_int8] = ACTIONS(45),
    [anon_sym_uint8] = ACTIONS(45),
    [anon_sym_int16] = ACTIONS(45),
    [anon_sym_uint16] = ACTIONS(45),
    [anon_sym_int32] = ACTIONS(45),
    [anon_sym_uint32] = ACTIONS(45),
    [anon_sym_int64] = ACTIONS(45),
    [anon_sym_uint64] = ACTIONS(45),
    [anon_sym_float32] = ACTIONS(45),
    [anon_sym_float64] = ACTIONS(45),
    [anon_sym_string] = ACTIONS(45),
    [anon_sym_time] = ACTIONS(45),
    [anon_sym_duration] = ACTIONS(45),
    [sym_identifier] = ACTIONS(45),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(47), 1,
      sym_const_name,
    ACTIONS(49), 1,
      sym_identifier,
    STATE(5), 1,
      sym_const_definition,
    STATE(6), 1,
      sym_field_name,
  [13] = 2,
    ACTIONS(51), 1,
      anon_sym_LBRACK,
    ACTIONS(53), 2,
      sym_const_name,
      sym_identifier,
  [21] = 2,
    ACTIONS(55), 1,
      anon_sym_LBRACK,
    ACTIONS(57), 2,
      sym_const_name,
      sym_identifier,
  [29] = 2,
    ACTIONS(59), 1,
      anon_sym_LBRACK,
    ACTIONS(61), 2,
      sym_const_name,
      sym_identifier,
  [37] = 1,
    ACTIONS(61), 2,
      sym_const_name,
      sym_identifier,
  [42] = 1,
    ACTIONS(63), 2,
      sym_const_name,
      sym_identifier,
  [47] = 1,
    ACTIONS(65), 1,
      sym_comment_string,
  [51] = 1,
    ACTIONS(67), 1,
      ts_builtin_sym_end,
  [55] = 1,
    ACTIONS(69), 1,
      anon_sym_EQ,
  [59] = 1,
    ACTIONS(71), 1,
      anon_sym_RBRACK,
  [63] = 1,
    ACTIONS(73), 1,
      sym_const_value,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(8)] = 0,
  [SMALL_STATE(9)] = 13,
  [SMALL_STATE(10)] = 21,
  [SMALL_STATE(11)] = 29,
  [SMALL_STATE(12)] = 37,
  [SMALL_STATE(13)] = 42,
  [SMALL_STATE(14)] = 47,
  [SMALL_STATE(15)] = 51,
  [SMALL_STATE(16)] = 55,
  [SMALL_STATE(17)] = 59,
  [SMALL_STATE(18)] = 63,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(14),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [25] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(9),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 2),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field_name, 1),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_field_name, 1),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field_definition, 2),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_field_definition, 2),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_definition, 3),
  [45] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_const_definition, 3),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_builtin_type, 1),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_builtin_type, 1),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_custom_type, 1),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_custom_type, 1),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_field_type, 1),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array_type, 3),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [67] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_ros(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
