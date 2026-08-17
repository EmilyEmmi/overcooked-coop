-- this is the translate command, it supports up to two blanks
function trans(id, ...)
  local usingLang = lang or "en"
  if not id then return "INVALID" end
  if not langdata then return id end

  if not langdata[usingLang] then
    usingLang = "en"
  end

  local translation = langdata[usingLang][id] or langdata["en"][id] or id
  if select("#", ...) > 0 then
    translation = string.format(translation, ...)
  end
  if translation == id then
    log_to_console("No translation for \""..id.."\"")
  end
  return translation
end

-- this is for scenarios where a word needs to be plural or not plural (usually "life/lives")
function trans_plural(id, ...)
  local count = select(-1, ...)
  if count ~= 1 then
    return trans(id, ...)
  else
    return trans(id .. "_one", ...)
  end
end

langdata = {} -- filled with each other file

-- this allows players to switch languages
function switch_lang(msg)
  msg = msg:lower()
  if langdata[msg] then
    lang = msg
    djui_chat_message_create(trans("switched"))
    return true
  end
  return false
end

-- debug command
function lang_test(msg)
  local args = split(msg or "", " ")
  if args[1] == "all" then
    local allLang = {}
    for lang, data in pairs(langdata) do
      if ((not args[2]) or lang == args[2]) and lang ~= "en" then
        table.insert(allLang, lang)
      end
    end
    if #allLang == 0 then
      djui_chat_message_create("Invalid language!")
      return true
    end

    for i, lang in ipairs(allLang) do
      local trans_missing = {}
      print("\n!!!!! Missing translation (" .. langdata[lang].fullname .. "): !!!!!")
      for id, phrase in pairs(langdata["en"]) do
        if id:sub(1, 6) ~= "debug_" and id:sub(1, 6) ~= "chara_" and not langdata[lang][id] then
          table.insert(trans_missing, id)
        end
      end
      table.sort(trans_missing)
      for i, id in ipairs(trans_missing) do
        local translated = trans(id, nil, nil, lang)
        djui_chat_message_create(id .. " lacks translation for " .. langdata[lang].fullname .. "!")
        print(string.format("%s = %q,", id, translated))
      end
    end
    return true
  end
  local id = args[1]
  local prevLang = lang
  if args[2] then
    lang = args[2]
  end

  if args[3] ~= "plural" then
    djui_chat_message_create(trans(id))
  else
    djui_chat_message_create(trans_plural(id, 1))
  end
  lang = prevLang

  return true
end

if cheatsApi then
    hook_chat_command("lang-test", "Test language", lang_test)
end

lang = "en"
lang_order_table = {}
function on_mods_loaded()
  -- this generates a list of available languages for the command description
  lang = "en"
  for lang, data in pairs(langdata) do
    table.insert(lang_order_table, lang)
  end
  table.sort(lang_order_table)

  -- this handles auto select
  for langname, data in pairs(langdata) do
    if data.fullname == smlua_text_utils_get_language() or (data.fullname == "Spanish" and data.fullname == smlua_text_utils_get_language():sub(1, -3)) then
      lang = langname
      break
    end
  end
end
hook_event(HOOK_ON_MODS_LOADED, on_mods_loaded)

-- load all language files
local langs = get_mod_files(get_active_mod(), "lang")
for i,langFile in ipairs(langs) do
  if langFile:sub(-4) == ".lua" then
    require(langFile:sub(1, -5))
  end
end