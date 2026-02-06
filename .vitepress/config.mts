import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "My C++ handbook",
  description: "Simple guide on how to get things done using C++",
  ignoreDeadLinks: true,
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: 'Start', link: '/exercises/0001-hello-world' },
    ],

    sidebar: [
      {
        text: 'Exercises',
        base:'/exercises',
        items: [
          { text: 'Hello World', link: '/0001-hello-world/' },
          { text: 'Basic Input', link: '/0002-basic-input/' },
          { text: 'Primitive Types', link: '/0003-primitive-types/' },
          { text: 'Control Structures', link: '/0004-control-structures/' },
          { text: 'Functions', link: '/0005-functions/' },
          { text: 'Pointers', link: '/0006-pointers/' },
          { text: 'Basic File I/O', link: '/0007-basic-file-io/' },
          { text: 'Modularity', link: '/0008-modularity/' },
          { text: 'Classes', link: '/0009-classes/' },
          { text: 'Functions part 2', link: '/0010-functions-lambdas/' },
        ]
      }
    ],

    socialLinks: [
      { icon: 'github', link: 'https://github.com/sombriks/my-cpp-handbook' },
      { icon: 'bluesky', link: 'https://bsky.app/profile/sombriks.com.br' }
    ]
  }
})
