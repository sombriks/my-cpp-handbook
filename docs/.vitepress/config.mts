import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "My C++ handbook",
  description: "Simple guide on how to get things done using C++",
  ignoreDeadLinks: true,
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: 'Home', link: '/' },
    ],

    sidebar: [
      {
        text: 'Exercises',
        items: [
          { text: 'Hello World', link: '/exercises/0001-hello-world' },
          { text: 'Basic Input', link: '/exercises/0002-basic-input' },
          { text: 'Primitive Types', link: '/exercises/0003-primitive-types' },
          { text: 'Control Structures', link: '/exercises/0004-control-structures' }
        ]
      }
    ],

    socialLinks: [
      { icon: 'github', link: 'https://github.com/sombriks/my-cpp-handbook' }
    ]
  }
})
